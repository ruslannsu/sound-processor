#include "config_parser.h"
#include "sound_processor.h"
#include <iostream>
#include <WAVreader.h>
#include <WAVWriter.h>

int main()
{
    Config conf("../config/config1.txt");

    //WAVReader W("../config/severe_tire_damage.wav");
  //  WAVWriter wr(W.samples_, W.header_, std::string("../config/write_checker.wav"));
   // wr.WriteToFile();
}
