#include <complex>

#include "config_parser.h"
#include "sound_processor.h"
#include <iostream>
#include <WAVreader.h>
#include <WAVWriter.h>
#include <converters.h>
#include <converter_creator.h>
#include <random>
int main(int argc, char *argv[])
{
   std::random_device r;
   std::default_random_engine e(r());
   std::uniform_int_distribution<int> dist(5,10);
   std::cout << dist(e);
   SoundProcessor sp(argc, argv);
   sp.Run();

   return 0;
}