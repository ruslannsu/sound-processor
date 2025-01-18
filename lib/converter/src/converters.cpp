#include "converters.h"


MuteConverter::MuteConverter(ConfigLine config_line):first_sec_(config_line.parameters_.at(0)), last_sec_(config_line.parameters_.at(1)){}

void MuteConverter::Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples)
{
    if (first_sec_ > last_sec_)
    {
        throw std::invalid_argument("Bad parameters for mute converter!");
    }
    for (size_t i = SAMPLING_RATE * first_sec_; i != SAMPLING_RATE * last_sec_; ++i)
    {
        try
        {
            samples.at(i) = 0;
        }
        catch(std::invalid_argument&)
        {
            throw std::invalid_argument("Something wrong with main file samples!");
        }
    }
}


MixConverter::MixConverter(ConfigLine config_line):start_sec_(config_line.parameters_.at(0)), file_link_(config_line.streams_.at(0))
{}



void MixConverter::Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples)
{
    if (SAMPLING_RATE * start_sec_ > samples.size())
    {
        throw std::invalid_argument("Bad first second for MixConverter");
    }
    for (size_t i = SAMPLING_RATE * start_sec_; i != samples.size(); ++i)
    {
        if (other_samples.at(file_link_ - 1).size() == i)
        {
            break;
        }
        samples.at(i) = (samples.at(i) + other_samples.at(file_link_ - 1 ).at(i)) / 2;
    }

}

RandomBoostConverter::RandomBoostConverter(ConfigLine config_line):start_range_(config_line.parameters_.at(0)), end_range_(config_line.parameters_.at(1)){}

void RandomBoostConverter::Convert(std::vector<sample> &samples, std::vector<std::vector<sample> > &other_samples)
{
    for(size_t i = 0; i != samples.size(); ++i)
    {
        std::random_device r;
        std::default_random_engine e(r());
        std::uniform_int_distribution<int> dist(start_range_,end_range_);
        samples.at(i)*=dist(e);
    }
}
