#pragma once

#include <string>
#include <functional>

// #include "sdkconfig.h"
// #include <ctype.h>
// #include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <utility>
// #include <exception>

//#include <esp_http_client.h>


class HTTPClient {


public:
    using Callback = std::function<void (HTTPClient*)>;

    int get(std::string &url);

    HTTPClient(const Callback &onDone);

    //, const std::string &user_agent, const char* ca_pem, int timeout = 5000);
    virtual ~HTTPClient();

    Callback doneCB;

    bool had_error = false;

    int exit_flag = 0;
    int status_code = 0;

    std::string body;

    std::string ca_pem;
    std::string user_agent;
    int timeout = 30000;
    std::string redirected_to;
    bool was_redirected = false;

  private:


};
