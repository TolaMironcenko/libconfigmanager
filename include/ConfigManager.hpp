#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

class ConfigManager
{
private:
    nlohmann::json config;
    std::fstream configfile;
    std::string configFileName;
public:
    ConfigManager();
    ConfigManager(nlohmann::json object);
    ConfigManager(std::string filename);
    ConfigManager(nlohmann::json object, std::string filename);
    ~ConfigManager();
    nlohmann::json getConfig();
    int setConfig(nlohmann::json object);
    int setConfig(std::string filename);
    int setConfigFile(std::string filename);
    std::string getParameterAsString(std::string paramName);
    int getParameterAsInt(std::string paramName);
    double getParameterAsDouble(std::string paramName);
    float getParameterAsFloat(std::string paramName);
    bool getParameterAsBool(std::string paramName);
    int setParameter(std::string name, int value);
    int setParameter(std::string name, double value);
    int setParameter(std::string name, float value);
    int setParameterAsNull(std::string name);
    int setParameter(std::string name, std::string value);
    int setParameter(std::string name, bool value);
    int saveConfig();
    int saveConfig(std::string filename);
    friend std::ostream& operator<<(std::ostream& out, const ConfigManager& manager);
};

#endif // CONFIG_MANAGER_HPP