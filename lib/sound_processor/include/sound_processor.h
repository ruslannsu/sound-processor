#pragma once
#include <vector>
#include <string>
#include "WAVReader.h"
#include "WAVWriter.h"
#include "config_parser.h"
#include "converters.h"
#include "converter_creator.h"

class SoundProcessor
{
public:
    SoundProcessor(int argc, char *argv[]);
    void Info();
    void Run();
private:
    std::vector<char> input_header_;
    std::vector<std::vector<sample>> input_samples_;
    std::string output_wav_file_;
    Config config_;
};