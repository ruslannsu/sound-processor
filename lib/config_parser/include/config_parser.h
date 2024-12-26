#pragma once
#include <string>
#include <vector>
#include <fstream>


struct Parameters
{
    std::string converter_type;
    size_t x;
    size_t y;
};


class Config
{
public:
    Config(std::string path);
    std::vector<Parameters> converters;
};