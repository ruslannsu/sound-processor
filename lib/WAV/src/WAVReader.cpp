#include <WAVreader.h>
#include <iostream>
#include <algorithm>

#include <fstream>
#include <array>



static void FindChunk(std::ifstream &ifs, uint32_t chunk_ID)
{
    Chunk buffer_struct{};
    while(true)
    {
        ifs.read((char*)&buffer_struct, sizeof(buffer_struct));
        if (buffer_struct.chunk_ID_ == chunk_ID)
        {
            std::cout << buffer_struct.size_ << std::endl;
            break;
        }
        ifs.seekg(buffer_struct.size_, std::ios::cur);
    }

}


static void ReadHeader(std::ifstream &ifs)
{
    Chunk buffer_riff_struct{};
    ifs.read((char*)&buffer_riff_struct, sizeof(buffer_riff_struct));
    if (buffer_riff_struct.chunk_ID_ != RIFF)
    {
        std::cout << "no riff" << std::endl;;
    }
    format_size format_buffer;
    ifs.read((char*)&format_buffer, sizeof(format_buffer));
    if (format_buffer != WAVE)
    {
        std::cout << "no fmt" << std::endl;
    }
    FindChunk(ifs, FMT);
    FMTChunkData buffer_fmt_struct{};
    ifs.read((char*)&buffer_fmt_struct, sizeof(buffer_fmt_struct));
    FindChunk(ifs, DATA);

}



WAVReader::WAVReader(std::string file): samples_(1, 0), header_(1, 0)
{
    std::ifstream ifs = std::ifstream(file, std::ios::in | std::ios::binary);
    ReadHeader(ifs);
    size_t header_size = ifs.tellg();
    header_.resize(header_size, 0);
    ifs.seekg(0, std::ios::end);
    size_t file_size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    ifs.read((char*)header_.data(), static_cast<long long>(header_size));
    samples_.resize(file_size - header_size, 0);
    ifs.read((char*)samples_.data(), static_cast<long long>(samples_.size()));
    for(size_t i = 0; i != samples_.size(); ++i)
    {
        if (samples_.at(i) % 1 == 0)
        {
            samples_.at(i) = 0;
        }
    }
}

















