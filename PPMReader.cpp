#include "PPMReader.hpp"
#include <sstream>
#include <set>

PPMReader::PPMReader(const std::string& imagePath)
{
    imageFile.open(imagePath, std::ios::in);
    if (imageFile.is_open())
    {
        name = imagePath;
        loadImageData();
    }
    else
    {
        std::cerr << "Blad pliku " << imagePath << std::endl;
    }
}

PPMReader::~PPMReader()
{
    if (imageFile.is_open())
    {
        imageFile.close();
    }
}

void PPMReader::loadImageData()
{
    std::string line;
    std::getline(imageFile, line); // P3
    if (line != "P3")
    {
        std::cerr << "Nieprawidlowy format pliku."<< std::endl;
        return;
    }

    while (imageFile.peek() == '#')
    {
        std::getline(imageFile, line);
    }

    imageFile >> width >> height >> maxColorValue;
    int r, g, b;
    while (imageFile >> r >> g >> b)
    {
        imageData.push_back(std::make_tuple(r, g, b));
    }

    
    for (const auto& color : imageData)
    {
        std::string colorStr = std::to_string(std::get<0>(color)) + "," + std::to_string(std::get<1>(color)) + "," +
            std::to_string(std::get<2>(color));
        colorFrequency[colorStr]++;
    }

}

void PPMReader::printImageInfo()
{
    std::cout << "Nazwa pliku: " << name << std::endl;
    std::cout << "Rozmiar obrazu: " << width << "x" << height << std::endl;
    std::cout << "Ilosc Pixeli: " << width * height << std::endl;
    std::cout << "Maksymalna wartosc koloru: " << maxColorValue << std::endl;
    std::cout << "Ilosc unikalnych kolorow: " << calcualteNumberOfUniqueColors() << std::endl;
}

void PPMReader::printMostFrequentColor()
{
    auto mostFrequent = getMostFrequentColor();
    std::cout << "Najczesciej wystepujacy kolor: " << mostFrequent.first << ", wystepuje " << mostFrequent.second << " razy"<< std::endl;
}

int PPMReader::calcualteNumberOfUniqueColors()
{
    auto uniqueColors = colorFrequency.size();
    return uniqueColors;
}

std::pair<std::string, int> PPMReader::getMostFrequentColor() const
{
    

    std::pair<std::string, int> mostFrequent{ "", 0 };
    for (const auto& pair : colorFrequency)
    {
        if (pair.second > mostFrequent.second)
        {
            mostFrequent = pair;
        }
    }

    return mostFrequent;
}
