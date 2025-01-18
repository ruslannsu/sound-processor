#include "converter_creator.h"






std::unique_ptr<Converter> MuteConverterCreator::Create(ConfigLine config_line)
{
    return std::make_unique<MuteConverter>(config_line);
}

std::unique_ptr<Converter> MixConverterCreator::Create(ConfigLine config_line)
{
    return std::make_unique<MixConverter>(config_line);
}

std::unique_ptr<Converter> RandomBoostConverterCreator::Create(ConfigLine config_line)
{
    return std::make_unique<RandomBoostConverter>(config_line);
}