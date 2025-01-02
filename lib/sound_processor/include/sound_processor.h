#pragma once
#include "config_parser.h"
#include <vector>
#include <string>

class SoundProcessor
{
public:
    SoundProcessor(int argc, char *argv[]);


private:
    std::vector<std::string> input_wav_files;
    std::string output_wav_file;
    Config config;


};