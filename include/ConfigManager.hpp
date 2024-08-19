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
    ConfigManager()
    {
        this->config = nullptr;
    }
    ConfigManager(nlohmann::json object)
    {
        this->config = object;
    }
    ConfigManager(std::string filename)
    {
        this->configfile.open(filename);
        this->config = nlohmann::json::parse(this->configfile);
        this->configfile.close();
        this->configFileName = filename;
    }
    ConfigManager(nlohmann::json object, std::string filename)
    {
        this->config = object;
        this->configFileName = filename;
    }
    ~ConfigManager()
    {
        this->config = nullptr;
        this->configfile.close();
    }
    nlohmann::json getConfig()
    {
        return this->config;
    }
    int setConfig(nlohmann::json object)
    {
        this->config = object;
        return 0;
    }
    int setConfig(std::string filename)
    {
        this->configfile.open(filename);
        this->config = nlohmann::json::parse(this->configfile);
        this->configFileName = filename;
        this->configfile.close();
        return 0;
    }
    int setConfigFile(std::string filename)
    {
        this->configFileName = filename;
        return 0;
    }
    std::string getParameterAsString(std::string paramName)
    {
        return this->config[paramName];
    }
    int getParameterAsInt(std::string paramName)
    {
        return this->config[paramName];
    }
    double getParameterAsDouble(std::string paramName)
    {
        return this->config[paramName];
    }
    float getParameterAsFloat(std::string paramName)
    {
        return this->config[paramName];
    }
    bool getParameterAsBool(std::string paramName)
    {
        return this->config[paramName];
    }
    int setParameter(std::string name, int value)
    {
        this->config[name] = value;
        return 0;
    }
    int setParameter(std::string name, double value)
    {
        this->config[name] = value;
        return 0;
    }
    int setParameter(std::string name, float value)
    {
        this->config[name] = value;
        return 0;
    }
    int setParameterAsNull(std::string name)
    {
        this->config[name] = nullptr;
        return 0;
    }
    int setParameter(std::string name, std::string value)
    {
        this->config[name] = value;
        return 0;
    }
    int setParameter(std::string name, bool value)
    {
        this->config[name] = value;
        return 0;
    }
    int saveConfig()
    {
        this->configfile.open(this->configFileName, std::ios::trunc | std::ios::out | std::ios::in);
        this->configfile << this->config.dump(4);
        this->configfile.close();
        return 0;
    }
    int saveConfig(std::string filename)
    {
        this->configfile.open(filename, std::ios::trunc | std::ios::out | std::ios::in);
        this->configfile << this->config.dump(4);
        this->configfile.close();
        return 0;
    }
    friend std::ostream& operator<<(std::ostream& out, const ConfigManager& manager)
    {
        return out << manager.config;
    }
};

#endif // CONFIG_MANAGER_HPP