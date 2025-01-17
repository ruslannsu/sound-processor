#pragma once
#include <config_parser.h>
#include <vector>
#include <WAVReader.h>
class Converter
{
public:
    virtual void Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples) = 0;
};



class MuteConverter : public Converter
{
public:
    MuteConverter(ConfigLine config_line);
    void Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples) override;
private:
    size_t first_sec_;
    size_t last_sec_;
};

class MixConverter : public Converter
{
public:
    MixConverter(ConfigLine config_line);
    void Convert(std::vector<sample> &samples, std::vector <std::vector<sample>> &other_samples) override;
private:
    size_t first_sec_;
    size_t file_link_;
};