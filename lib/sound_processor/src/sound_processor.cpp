#include "sound_processor.h"
#include "map"



SoundProcessor::SoundProcessor(int argc, char *argv[]):config_(std::string(argv[2])), output_wav_file_(std::string(argv[3])), input_wav_files_()
{
    for (size_t i = 0; i != argc; ++i)
    {
        input_wav_files_.push_back(WAVReader(std::string(argv[i])));
    }

}

