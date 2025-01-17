#pragma once
#include <vector>
#include "WAVfile.h"
#include <fstream>

class WAVReader
{
public:
    WAVReader(std::string file);
    std::vector<sample> &GetSamples();
    std::vector<char> &GetHeader();
private:
    std::vector<sample> samples_;
    std::vector<char> header_;
};