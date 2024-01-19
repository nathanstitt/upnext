/*

Credit to COERT VONK https://coertvonk.com/sw/embedded/esp8266-clock-import-events-from-google-calendar-15809
Have followed his example, and added multi-calendar support, where all events from "selected" calendars are fetched, and sorted before being returned to the caller

You need to put this up as a public script. Please note that this will expose your calendar entries to the internet - however, only you have the unique id - and there is no input or write access.

If you find a solution that can avoid it, then please share and I will update the guide

*/

function doGet(e) {
  var calendars = CalendarApp.getAllCalendars();

  if (calendars == undefined) {
    Logger.log("No data");
    return ContentService.createTextOutput(JSON.stringify({error: "No Calendars", events: [] })).setMimeType(ContentService.MimeType.JSON);
  }

  //calendars.forEach(c => { Logger.log(c.getName());})

  const now = new Date();
  var start = new Date(); start.setHours(0, 0, 0);  // start at midnight
  const oneday = 24 * 3600000; // [msec]
  const stop = new Date(start.getTime() + 2 * oneday); //get appointments for the next 14 days

  var events = mergeCalendarEvents(calendars, start, stop); //pull start/stop time

  var reportedEvents = [];
  for (var ii = 0; ii < events.length; ii++) {
    var event = events[ii];
    var evStatus = event.getMyStatus();

    // Logger.log(event.getTitle())
    // Logger.log(event.getGuestList())
    // Logger.log(evStatus)
    // Logger.log(event.isOwnedByMe())

    if (!event.isAllDayEvent() && (
      evStatus == CalendarApp.GuestStatus.MAYBE || evStatus == CalendarApp.GuestStatus.YES || evStatus == CalendarApp.GuestStatus.OWNER ||
      event.getGuestList().length == 0 // entries on a subscribed cal that you did not create but have no guests are likely for "everyone"
    )) {
      reportedEvents.push({
        title: event.getTitle(),
        startAt: event.getStartTime(),
        endAt: event.getEndTime(),
        allDay: event.isAllDayEvent(),
      })
    }
  }

  Logger.log(JSON.stringify(reportedEvents, null, 4));

  return ContentService.createTextOutput(JSON.stringify({ events: reportedEvents })).setMimeType(ContentService.MimeType.JSON);

  return ContentService.createTextOutput(str);

}

function mergeCalendarEvents(calendars, startTime, endTime) {

  var params = { start: startTime, end: endTime, uniqueIds: [] };

  return calendars.map(toUniqueEvents_, params)
    .reduce(toSingleArray_)
    .sort(byStart_);
}

function toUniqueEvents_(calendar) {
  return calendar.getEvents(this.start, this.end)
    .filter(onlyUniqueEvents_, this.uniqueIds);
}

function onlyUniqueEvents_(event) {
  var eventId = event.getId();
  var uniqueEvent = this.indexOf(eventId) < 0;
  if (uniqueEvent) this.push(eventId);
  return uniqueEvent;
}

function toSingleArray_(a, b) { return a.concat(b) }

function byStart_(a, b) {
  return a.getStartTime().getTime() - b.getStartTime().getTime();
}
