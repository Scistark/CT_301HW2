#ifndef HW2_h
#define HW2_h

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class HW2class{
    public:
    ifstream ppmImage;
    ifstream checksumfile;
    int ppmimagerowwidth= 0;
    int ppmimageheight= 0;
    int maximumppmpixelvalue= 0;
    int currentppmimagerow = 0;

    void updateImageFiles(string ppm, string checksum);
    void ChecktoseeifImageOpened();
    void CheckppmHeader();
    void PPMimageHeightLength();

    int CurrentRowOfPPMfile= 0;
    void PPMnumbersBackbone();
    void checkonlyIntegers(char integer, int linenumber);

    int CurrentpixelCountForaRow= 0;
    int totalforline= 0;

    void CalculatingHashForcurrentRow(int intoadd);
    int errorcheckchecksumfile(string checksumstring, int checksumlinenumber);

    int checksumfileline= 0;
    void comparingagenstchecksumfile(int ppmhash, int line);
};
#endif