#include "converters.h"


MuteConverter::MuteConverter(ConfigLine config_line):first_sec_(config_line.parameters_.at(0)), last_sec_(config_line.parameters_.at(1)){}

void MuteConverter::Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples)
{
    for (size_t i = SAMPLING_RATE * first_sec_; i != SAMPLING_RATE * last_sec_; ++i)
    {
        samples.at(i) = 0;
    }
}


MixConverter::MixConverter(ConfigLine config_line):first_sec_(config_line.parameters_.at(1)), file_link_(config_line.streams_.at(0)){}



void MixConverter::Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples)
{
    for (size_t i = SAMPLING_RATE * first_sec_; i != samples.size(); ++i)
    {
        samples.at(i) = (samples.at(i) + other_samples.at(file_link_).at(i)) / 2;
    }
}
