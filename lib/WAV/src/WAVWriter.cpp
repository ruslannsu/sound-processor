#include <fstream>
#include "WAVWriter.h"

WAVWriter::WAVWriter(std::vector<sample> &samples, std::vector<char> &header, std::string output_file_path):output_header_(header), output_samples_(samples), output_file_path_(output_file_path){}

void WAVWriter::WriteToFile()
{
    std::ofstream ofs(output_file_path_, std::ios::out | std::ios::binary);
    if (!(ofs.is_open()))
    {
        throw std::invalid_argument("Something wrong with writing to file, try again!");
    }
    ofs.write((char*)output_header_.data(), static_cast<long long>(output_header_.size()));
    ofs.write((char*)output_samples_.data(), static_cast<long long>(output_samples_.size()));
}
