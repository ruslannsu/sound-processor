#include <complex>
#include "sound_processor.h"
#include <iostream>
#include <random>
int main(int argc, char *argv[])
{
   SoundProcessor sp(argc, argv);
   sp.Info();
   sp.Run();
   return 0;
}