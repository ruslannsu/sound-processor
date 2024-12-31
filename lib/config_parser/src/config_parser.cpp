#include "config_parser.h"
#include <iostream>


Config::Config(std::string path)
{
    std::ifstream file(path);
    std::string buffer;
    if (file.is_open())
    {
        std::cout << "file has opened" << std::endl;
        while(getline(file, buffer))
        {
            converters.push_back(buffer);
        }
    }
    else
    {
        throw std::invalid_argument("Incorrect path");
    }
}


