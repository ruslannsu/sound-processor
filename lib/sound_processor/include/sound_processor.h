#pragma once
#include "config_parser.h"
#include <vector>
#include <string>
#include <WAVReader.h>

class SoundProcessor
{
public:
    SoundProcessor(int argc, char *argv[]);

private:
    std::vector<WAVReader> input_wav_files_;
    std::string output_wav_file_;
    Config config_;
};