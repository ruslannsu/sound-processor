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
    for (size_t i = 0; i != config_.size(); ++i)
    {
        std::cout << config_.at(i).converter_name_ << ' ';

        for (size_t j = 0; j != config_.at(i).parameters_.size(); ++j)
        {
            std::cout << config_.at(i).parameters_.at(j) << ' ';
        }
        for (size_t j = 0; j != config_.at(i).streams_.size(); ++j)
        {
            std::cout << config_.at(i).streams_.at(j) << ' ';
        }
        std::cout << std::endl;
    }
}


