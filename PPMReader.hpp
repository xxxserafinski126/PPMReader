#ifndef _PPMREADER_HPP_
#define _PPMREADER_HPP_

#include "ImageReader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class PPMReader : public ImageReader
{
public:
    PPMReader(const std::string& imagePath);
    ~PPMReader();

    void printImageInfo() override;
    void printMostFrequentColor() override;
    int calcualteNumberOfUniqueColors() override;

private:
    std::fstream imageFile;
    std::vector<std::tuple<int, int, int>> imageData;
    int width;
    int height;
    int maxColorValue;
    std::string name;

    void loadImageData();
    std::pair<std::string, int> getMostFrequentColor() const;
    std::map<std::string, int> colorFrequency;
};

#endif // _PPMREADER_HPP_