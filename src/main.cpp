#include "sound_processor.h"

int main(int argc, char *argv[])
{
   SoundProcessor sp(argc, argv);
   sp.Info();
   sp.Run();
   return 0;
}