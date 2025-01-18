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
            ConfigLine line{};
            bool is_name(true);
            size_t string_pos = 0;
            for (size_t i = 0; i != buffer.size(); ++i)
            {
                if ((buffer.at(i) == ' ') || (buffer.size() - 1 == i))
                {
                    if (is_name)
                    {
                        line.converter_name_ = buffer.substr(0, i);
                        is_name = false;
                        string_pos = i + 1;
                    }
                    else
                    {
                        if (buffer.substr(string_pos, i + 1).at(0) == '$')
                        {
                            line.streams_.push_back(stoi(buffer.substr(string_pos + 1, i + 1)));
                            string_pos = i + 1;
                        }
                        else
                        {
                            line.parameters_.push_back(stoi(buffer.substr(string_pos, i + 1)));
                            string_pos = i + 1;
                        }
                    }
                }
            }
            config_.push_back(line);
        }
    }
    else
    {
        throw std::invalid_argument("Incorrect path");
    }
}


std::vector<ConfigLine>& Config::GetConfig()
{
    return config_;
}



