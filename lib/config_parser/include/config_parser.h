#pragma once
#include <string>
#include <vector>
#include <fstream>



struct ConfigLine
{
    std::string converter_name_;
    std::vector<int> parameters_;
    std::vector<size_t> streams_;
};

class Config
{
public:
    Config(std::string path);
    std::vector<ConfigLine> &GetConfig();
private:
    std::vector<ConfigLine> config_;
};