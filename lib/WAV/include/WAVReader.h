#pragma once
#include <vector>
#include <fstream>
#include "WAVfile.h"

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