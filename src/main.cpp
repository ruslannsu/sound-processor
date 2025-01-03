#include "config_parser.h"
#include "sound_processor.h"
#include <iostream>
#include <WAVreader.h>
#include <WAVWriter.h>

int main()
{
    WAVReader W("../config/funkorama.wav");
    WAVWriter wr(W.samples_, W.header_, std::string("../config/write_checker.wav"));
    wr.WriteToFile();
}
