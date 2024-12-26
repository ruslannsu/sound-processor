#include "config_parser.h"
#include <iostream>

static Parameters ParametersScan(std::string &buffer)
{
    Parameters parameters;
    size_t pos = buffer.find(' ');
    if (pos == std::string::npos)
    {
        throw std::invalid_argument("Incorrect config");
    }
    parameters.converter_type = buffer.substr(0, pos);
    size_t next_pos = (buffer.substr(pos + 1, buffer.size())).find(' ') + pos;
    if (next_pos == std::string::npos)
    {
        throw std::invalid_argument("Incorrect config");
    }
    parameters.x = stoi(buffer.substr(pos + 1, next_pos));
    parameters.y = stoi(buffer.substr(next_pos + 1, buffer.size()));
    return parameters;
}



Config::Config(std::string path)
{
    std::ifstream file(path);
    std::string buffer;
    if (file.is_open())
    {
        std::cout << "file has opened" << std::endl;
        while(getline(file, buffer))
        {
            converters.push_back(ParametersScan(buffer));
        }
    }
    else
    {
        throw std::invalid_argument("Incorrect path");
    }
}


