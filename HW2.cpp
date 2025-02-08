#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

class HW2class{
    public:
    ifstream ppmImage;
    ifstream checksumfile;

    void updateImageFiles(string ppm, string checksum){
        ppmImage.open(ppm);
        checksumfile.open(checksum);
    }
};
int main(int argc, char* argv[]) {
    //make sure that the input is the right number
    if(argc >= 3){
        cout << argv[3];
        HW2class test1;
        test1.updateImageFiles(argv[1],argv[2]);

    }else{
        cout << "add correct input amount\n";
        return -1;

    }
    return 0;
}