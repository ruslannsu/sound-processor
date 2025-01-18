#include <WAVreader.h>
#include <algorithm>
#include <fstream>



std::vector<sample> &WAVReader::GetSamples()
{
    return samples_;
}

std::vector<char> &WAVReader::GetHeader()
{
    return header_;
}


static void FindChunk(std::ifstream &ifs, uint32_t chunk_ID)
{
    Chunk buffer_struct{};
    while(true)
    {
        ifs.read((char*)&buffer_struct, sizeof(buffer_struct));
        if (buffer_struct.chunk_ID_ == chunk_ID)
        {
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
        throw std::invalid_argument("Bad header: bad RIFF");
    }
    format_size format_buffer;
    ifs.read((char*)&format_buffer, sizeof(format_buffer));
    if (format_buffer != WAVE)
    {
        throw std::invalid_argument("Bad header: bad WAVE");
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
}

















