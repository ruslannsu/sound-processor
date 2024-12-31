#pragma once
#include <string>
#include <vector>
#include <fstream>





class Config
{
public:
    Config(std::string path);
    std::vector<std::string> converters;
};