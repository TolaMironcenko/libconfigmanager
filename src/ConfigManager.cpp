#include "ConfigManager.hpp"

ConfigManager::ConfigManager()
{
    this->config = nullptr;
}
ConfigManager::ConfigManager(nlohmann::json object)
{
    this->config = object;
}
ConfigManager::ConfigManager(std::string filename)
{
    this->configfile.open(filename);
    this->config = nlohmann::json::parse(this->configfile);
    this->configfile.close();
    this->configFileName = filename;
}
ConfigManager::ConfigManager(nlohmann::json object, std::string filename)
{
    this->config = object;
    this->configFileName = filename;
}
ConfigManager::~ConfigManager()
{
    this->config = nullptr;
    this->configfile.close();
}
nlohmann::json ConfigManager::getConfig()
{
    return this->config;
}
int ConfigManager::setConfig(nlohmann::json object)
{
    this->config = object;
    return 0;
}
int ConfigManager::setConfig(std::string filename)
{
    this->configfile.open(filename);
    this->config = nlohmann::json::parse(this->configfile);
    this->configFileName = filename;
    this->configfile.close();
    return 0;
}
int ConfigManager::setConfigFile(std::string filename)
{
    this->configFileName = filename;
    return 0;
}
std::string ConfigManager::getParameterAsString(std::string paramName)
{
    return this->config[paramName];
}
int ConfigManager::getParameterAsInt(std::string paramName)
{
    return this->config[paramName];
}
double ConfigManager::getParameterAsDouble(std::string paramName)
{
    return this->config[paramName];
}
float ConfigManager::getParameterAsFloat(std::string paramName)
{
    return this->config[paramName];
}
bool ConfigManager::getParameterAsBool(std::string paramName)
{
    return this->config[paramName];
}
int ConfigManager::setParameter(std::string name, int value)
{
    this->config[name] = value;
    return 0;
}
int ConfigManager::setParameter(std::string name, double value)
{
    this->config[name] = value;
    return 0;
}
int ConfigManager::setParameter(std::string name, float value)
{
    this->config[name] = value;
    return 0;
}
int ConfigManager::setParameterAsNull(std::string name)
{
    this->config[name] = nullptr;
    return 0;
}
int ConfigManager::setParameter(std::string name, std::string value)
{
    this->config[name] = value;
    return 0;
}
int ConfigManager::setParameter(std::string name, bool value)
{
    this->config[name] = value;
    return 0;
}
int ConfigManager::saveConfig()
{
    this->configfile.open(this->configFileName, std::ios::trunc | std::ios::out | std::ios::in);
    this->configfile << this->config.dump(4);
    this->configfile.close();
    return 0;
}
int ConfigManager::saveConfig(std::string filename)
{
    this->configfile.open(filename, std::ios::trunc | std::ios::out | std::ios::in);
    this->configfile << this->config.dump(4);
    this->configfile.close();
    return 0;
}
