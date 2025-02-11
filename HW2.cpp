#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include "HW2.h"
using namespace std;


    void HW2class::updateImageFiles(string ppm, string checksum){
        ppmImage.open(ppm);
        checksumfile.open(checksum);
        ChecktoseeifImageOpened();
        CheckppmHeader();
        PPMimageHeightLength();
        PPMnumbersBackbone();
        cout<<"success"<<endl;
    }
    void HW2class::ChecktoseeifImageOpened(){
        if(ppmImage.is_open()){
            if(checksumfile.is_open()){
                //cout << "PPM and Checksum is open" << endl;
                }
            else{
                //my checksum image did not open
                exit(-1);
                }
            }
            else{
                //my ppm image did not open
                exit(-1);
                }
        }
    void HW2class::CheckppmHeader(){
        string firstline;
        getline(ppmImage, firstline);
        if(firstline.find("P3") > 10){
            //means that it was not in atleast the first 10 values
            exit(-1);
        }else{
            //cout << "Correct P3 Header" << endl;
        }
    }
    void HW2class::PPMimageHeightLength(){
        string secondline;

        //getting the second line and turing into stream
        getline(ppmImage, secondline);
        stringstream infostream(secondline);

        //casting width from stream and checking of valid
        infostream >> ppmimagerowwidth;
        //cout << "Width  "<< ppmimagerowwidth <<endl;
        if(ppmimagerowwidth  < 0){
            exit(-1);
        }
        //casting height from stream checking if valid
        infostream >> ppmimageheight;
        //cout << "Height  "<< ppmimageheight <<endl;
        if(ppmimageheight  < 0){
            exit(-1);
        }
        //casting max pixle value and checking if valid
        infostream >> maximumppmpixelvalue;
        //cout << "Maximum pixle  "<< maximumppmpixelvalue <<endl;
        if(maximumppmpixelvalue  < 0|| maximumppmpixelvalue > 255){
            exit(-1);
        }

    }

    int CurrentRowOfPPMfile = 0;


    void HW2class::PPMnumbersBackbone(){
        string ppmlinestring;

        //going throught each line of ppm file
        while(getline(ppmImage, ppmlinestring)){
            currentppmimagerow++;

        //verifying that each char is an integer    
        for(char integer : ppmlinestring){
            checkonlyIntegers(integer,CurrentRowOfPPMfile);
        }

        //once you know every number is valid
        stringstream streamversionofstring(ppmlinestring);
        int currentpixelvalue = 0;

        //this streams every pixel into that int and runs the method on them
        while(streamversionofstring >> currentpixelvalue){
            //if(currentpixelvalue > maximumppmpixelvalue){exit(-(currentppmimagerow)+2);}
            CalculatingHashForcurrentRow(currentpixelvalue);

        }
        //this runs after the ENTIRE ppm image is iterated through
    }
    if(CurrentpixelCountForaRow != 0){
        //cout << "incorrect amount of pixles" << endl;
        exit(-1);
    }
    string checksumstring;
    if(checksumfile.peek() != EOF){
        cout << "Checksum file is longer than image" << endl;
        exit(-1);
    }
    }
    void HW2class::checkonlyIntegers(char integer, int linenumber){
        if(integer == '\n'|| integer == ' '){
        }else{
            if(isdigit(integer)){
                //should i connect here or later?
            }else{
                //cout << "Error in row"<<linenumber<< endl;
                exit(-1);
            }

        }
    }

    void HW2class::CalculatingHashForcurrentRow(int intoadd){
        //it comiles the total sum together and resets for the new information to be passed in
        //that equation detects when it is reading the second to last pixel value in row
        if(CurrentpixelCountForaRow == ((ppmimagerowwidth)*3)-1){
            
            totalforline = totalforline + intoadd;
            //cout << "total sum"<<totalforline << " for line "<< CurrentRowOfPPMfile << endl;
            comparingagenstchecksumfile(totalforline,CurrentRowOfPPMfile);
            CurrentRowOfPPMfile++;
            CurrentpixelCountForaRow = 0;
            totalforline = 0;
        }
        else{
            //cout<<"three tracker = "<<CurrentpixelCountForaRow<<"totalforline ="<<totalforline<<" "<<intoadd<<endl;
            CurrentpixelCountForaRow++;
            totalforline = totalforline + intoadd;
        }
    }

    int HW2class::errorcheckchecksumfile(string checksumstring, int checksumlinenumber){
        for(char integer : checksumstring){
            checkonlyIntegers(integer,checksumlinenumber);
        }
        //checkonlyIntegers()
        return stoi(checksumstring);
    }

    int checksumfileline = 0;
    void HW2class::comparingagenstchecksumfile(int ppmhash, int line){
        string checksumstring;
        if(checksumfile.peek() == EOF){
            cout << "checksum file is to short" << endl;
            exit(-1);
        }
        //cout << "total sum"<<ppmhash << " for line "<< line << endl;
        getline(checksumfile, checksumstring);
        //checkonlyIntegers(checksumstring, checksumfileline);
        int errorchecksumfileint = errorcheckchecksumfile(checksumstring, checksumfileline);
        if(ppmhash == errorchecksumfileint){
            //cout << "THEY MACH "<< ppmhash << " AND " << errorchecksumfileint << endl;
            checksumfileline++;
        }else{
            //cout << "THEY DONT MATCH MACH "<< ppmhash << " AND " << errorchecksumfileint << endl;
            cout << "Error in row"<<currentppmimagerow<< endl;
            exit(-(currentppmimagerow + 2));
            //checksumfileline++;
        }
        
    }
int main(int argc, char* argv[]) {

    //make sure that the input is the right number
    if(argc == 3){
        //cout << argv[1] <<endl;
        HW2class test1;
        test1.updateImageFiles(argv[1],argv[2]);
        return 0;

    }else{
        //cout << "add correct input amount\n";
        //HW2class test1;
        //test1.updateImageFiles("Test.ppm","checksumscorrected.txt");
        //test1.updateImageFiles("checksumscorrected.txt","Test.ppm");
        return -1;

    }
    return 0;
}