#include <complex>
#include "sound_processor.h"
#include <iostream>
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