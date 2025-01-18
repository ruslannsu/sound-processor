#pragma once
#include "config_parser.h"
#include <vector>
#include <string>
#include <WAVReader.h>
#include <WAVWriter.h>
#include "converters.h"
#include "converter_creator.h"

class SoundProcessor
{
public:
    SoundProcessor(int argc, char *argv[]);
    void Run();
private:
    std::vector<char> input_header_;
    std::vector<std::vector<sample>> input_samples_;
    std::string output_wav_file_;
    Config config_;
};