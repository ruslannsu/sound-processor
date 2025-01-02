#pragma once
#include <iostream>
#include <cstdint>

const uint32_t RIFF = 0x46464952;
const uint32_t WAVE = 0x45564157;
const uint32_t FMT = 0x20746d66;
const uint32_t DATA = 0x61746164;

const uint16_t AUDIO_FORMAT_PCM = 0x0001;
const uint16_t NUM_CHANNELS = 1;
const uint32_t SAMPLING_RATE = 44100;
const uint16_t BITS_PER_BYTE = 8;
const uint16_t BITS_PER_SAMPLE = BITS_PER_BYTE * sizeof(int16_t);
const uint16_t BLOCK_ALIGN = BITS_PER_SAMPLE * NUM_CHANNELS / BITS_PER_BYTE;
const uint32_t BYTE_RATE = BLOCK_ALIGN * SAMPLING_RATE;

struct Chunk
{
    uint32_t chunk_ID_;
    uint32_t size_;
};

using format_size =  uint32_t;

struct FMTChunkData
{
    uint16_t audioFormat_ = AUDIO_FORMAT_PCM;
    uint16_t numChannels_ = NUM_CHANNELS;
    uint32_t sampleRate_ = SAMPLING_RATE;
    uint32_t byteRate_ = BYTE_RATE;
    uint16_t blockAlign_ = BLOCK_ALIGN;
    uint16_t bitsPerSample_ = BITS_PER_SAMPLE;
};

using sample = int16_t;
