#pragma once
#include <string>
#include <vector>
#include <fstream>




struct ConfigLine
{
    std::string converter_name_;
    std::vector<int> parameters_;
};

class Config
{
public:
    Config(std::string path);
    std::vector<ConfigLine> config_;
};