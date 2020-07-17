#include "ToolConfig.h"
#include <stdio.h>
#define CONFIG_FILE_NAME "TcpEncodeForward.data"
ToolConfig::ToolConfig()
{
}


ToolConfig::~ToolConfig()
{
}

Config ToolConfig::getConfig()
{
    FILE* file = fopen(CONFIG_FILE_NAME, "rb");
    Config config;
    if (!file) {
        return config;
    }
    fread(&config, 1, sizeof(Config), file);
    fclose(file);
    return config;
}

bool ToolConfig::setConfig(Config & config)
{
    FILE* file = fopen(CONFIG_FILE_NAME, "wb");
    if (!file) {
        return false;
    }
    fwrite(&config, 1, sizeof(Config), file);
    fclose(file);
    return true;
}
