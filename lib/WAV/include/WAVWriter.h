#pragma once
#include <string>
#include <vector>
#include "WAVfile.h"

class WAVWriter
{
public:
    WAVWriter(std::vector<sample> &samples, std::vector<char> &header, std::string output_file_path);
    void WriteToFile();
private:
    std::vector<char> &output_header_;
    std::vector<sample> &output_samples_;
    std::string output_file_path_;
};
