#pragma once
#include <string>
struct Config
{
    char sRemoteIP[256];
    char sEncodeKey[256];
    int nRemortPort;
    int nLocalPort;
    int nShowMsg;
    int nIsEncode;
    Config() {
        nRemortPort = 27070;
        nLocalPort = 27070;
        memset(sRemoteIP, 0, 256);
        memset(sEncodeKey, 0, 256);
        memcpy(sEncodeKey, "0xB7", sizeof("0xB7"));
        nShowMsg = true;
        nIsEncode = true;
    }
};

class ToolConfig
{
protected:
    ToolConfig();
    ~ToolConfig();

public:
    static ToolConfig* getInstance() {
        static ToolConfig config;
        return &config;
    }
    Config getConfig();
    bool setConfig(Config& config);
};

