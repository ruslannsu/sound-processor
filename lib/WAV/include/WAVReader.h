#pragma once
#include <vector>
#include "WAVfile.h"
#include <fstream>

class WAVReader
{
public:
    WAVReader(std::string file);
public:
    std::vector<sample> samples_;
    std::vector<char> header_;
};