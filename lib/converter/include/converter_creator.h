#pragma once
#include <memory>

#include "converters.h"


class ConverterCreator
{
public:
    virtual std::unique_ptr<Converter> Create(ConfigLine config_line) = 0;
    virtual ~ConverterCreator() = default;
};



class MuteConverterCreator : ConverterCreator
{
public:
    std::unique_ptr<Converter> Create(ConfigLine config_line) override;
};



class MixConverterCreator : ConverterCreator
{
public:
    std::unique_ptr<Converter> Create(ConfigLine config_line) override;
};

class RandomBoostConverterCreator : ConverterCreator
{
public:
    std::unique_ptr<Converter> Create(ConfigLine config_line) override;
};