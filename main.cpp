#include <iostream>
#include "PPMReader.hpp"

int main()
{
    PPMReader ppmReader("x1.ppm");

    std::cout << "Informacje o obrazie PPM:" << std::endl;
    ppmReader.printImageInfo();
    ppmReader.printMostFrequentColor();
    

    std::cout << std::endl;

    PPMReader ppmReader2("x2.ppm");

    std::cout << "Informacje o obrazie PPM:" << std::endl;
    ppmReader2.printImageInfo();
    ppmReader2.printMostFrequentColor();

    return 0;
}