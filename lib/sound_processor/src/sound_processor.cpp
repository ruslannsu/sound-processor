#include "sound_processor.h"
#include "map"



SoundProcessor::SoundProcessor(int argc, char *argv[]):config(std::string(argv[2]))
{
    output_wav_file = std::string(argv[3]);
    for (size_t i = 4; i != argc; ++i)
    {
        input_wav_files.push_back(std::string(argv[i]));
    }
}

