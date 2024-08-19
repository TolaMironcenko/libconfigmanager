#include <iostream>
#include "ConfigManager.hpp"

int main()
{
    ConfigManager manager(std::string("config.json"));
    // bool is_superuser = manager.getParameterAsBool("is_superuser");
    std::cout << manager.getParameterAsFloat("id") << std::endl;
    manager.saveConfig();
    return 0;
}
