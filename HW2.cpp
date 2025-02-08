#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class HW2class{
    public:
    ifstream ppmImage;
    ifstream checksumfile;

    void updateImageFiles(string ppm, string checksum){
        ppmImage.open(ppm);
        checksumfile.open(checksum);
        ChecktoseeifImageOpened();
        CheckppmHeader();
        PPMimageHeightLength();
        PPMnumbersBackbone();
    }
    void ChecktoseeifImageOpened(){
        if(ppmImage.is_open()){
            if(checksumfile.is_open()){
                cout << "PPM and Checksum is open" << endl;}
            else{
                exit(-1);
                }
            }
            else{
                exit(-1);
                }
        }
    void CheckppmHeader(){
        string str;
        string str2;
        getline(ppmImage, str);
        if(str.find("P3") > 10){
            exit(-1);
        }else{
            cout << "Correct P3 Header" << endl;
        }
    }
    void PPMimageHeightLength(){
        string str;
        int streamheight;
        getline(ppmImage, str);
        stringstream infostream(str);
        infostream >> streamheight;
        cout << "Width  "<< streamheight <<endl;
        infostream >> streamheight;
        if(streamheight  < 0){
            exit(-1);
        }
        cout << "Height  "<< streamheight <<endl;
        infostream >> streamheight;
        if(streamheight  < 0){
            exit(-1);
        }
        cout << "Maximum pixle  "<< streamheight <<endl;
        if(streamheight  < 0|| streamheight > 255){
            exit(-1);
        }

    }
    int ppmlinecalculating = 0;
    int threenumbertracker = 0;
    int totalforline = 0;


    void PPMnumbersBackbone(){
        string ppmlinestring;
        int currentppmline = 0;
        int currentchecksumline = 0;
        //going throught each line of ppm file
        while(getline(ppmImage, ppmlinestring)){
        //verifying that each char is an integer    
        for(char integer : ppmlinestring){
            checkonlyIntegers(integer,currentppmline);
        }
        //once you know every number is valid
        //cout << str << endl;
        stringstream streamversionofstring(ppmlinestring);
        int totalint = 0;
        while(streamversionofstring >> totalint){
            addingIntegerToSumforpixel(totalint);
            //cout << totalint <<" TOOINT\n" << endl;

        }
    }
    }
    void checkonlyIntegers(char integer, int linenumber){
        if(integer == '\n'|| integer == ' '){
        }else{
            if(isdigit(integer)){
                //should i connect here or later?
            }else{
                cout << "failed at "<< integer << " line " << linenumber << endl;
                exit(-1);
            }

        }
    }
    void addingIntegerToSumforpixel(int intoadd){
        //cout << "total sum ="<<totalforline << " for line "<< ppmlinecalculating<< "int to add    "<< intoadd << endl;
        //i execute this when the next number being added is the third number
        //it comiles the total sum together and resets for the new information to be passed in
        if(threenumbertracker == 2){
            
            totalforline = totalforline + intoadd;
            //cout << "total sum"<<totalforline << " for line "<< ppmlinecalculating << endl;
            comparingagenstchecksumfile(totalforline,ppmlinecalculating);
            ppmlinecalculating++;
            threenumbertracker = 0;
            totalforline = 0;
        }
        else{
            threenumbertracker++;
            totalforline = totalforline + intoadd;

        }

    }
    int errorcheckchecksumfile(string checksumstring){
        return stoi(checksumstring);
    }
    void comparingagenstchecksumfile(int ppmhash, int line){
        string checksumstring;
        cout << "total sum"<<ppmhash << " for line "<< line << endl;
        getline(checksumfile, checksumstring);
        if(ppmhash == errorcheckchecksumfile(checksumstring)){
            cout << " THEY MACH "<< ppmhash << " AND " << errorcheckchecksumfile(checksumstring) << endl;
        }else{
            cout << " THEY DONT MATCH MACH "<< ppmhash << " AND " << errorcheckchecksumfile(checksumstring) << endl;
        }
        
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
        HW2class test1;
        test1.updateImageFiles("Test.ppm","checksums.txt");
        return -1;

    }
    return 0;
}