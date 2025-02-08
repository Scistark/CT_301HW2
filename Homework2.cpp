//#include <Homework2.h>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cctype>
#include<climits>
#include <list>

class testingopeningfile {
    int checksumsarray;

    void OpeningchecksumsAndCountingvalues(){
        
    }

    //thses lines are for the puroses of adding and creating blocks of three
    int numberof3 = 0;
    int totalofthethree = 0;
    int trackofcalcuatedhashesline = 0;

    int checkifaninteger(char currentint, int linenumber){
        //checks if it is the first line 
        if(linenumber == 0){
            //cout << "line 0"<<currentint<<endl;
        }else{
        if(linenumber == 0||currentint == '\n' || currentint == ' '){
            //cout << "skipped ="<<currentint<<endl;
            return 0;}else{
        if(isdigit(currentint)){
            int answer = static_cast<int>(currentint);
            //cout<<"sucsessded at  "<< currentint<< linenumber<<endl;
            return answer;
        }else{
            cout<<"failed at"<< currentint<< linenumber<<endl;
            exit(-1);
        }
    }
}
    }
    public:
    void OpeningImageppmFile(){
    //string filetext;
    ifstream ImageppmFile;
    string currentLineOfImageString;
    ImageppmFile.open("Test.ppm");
    int linenumber = 0;




    //this while loop interates through all the lines
    while(getline(ImageppmFile,currentLineOfImageString)){
        //this makes sure that there are only integers in the line
        for(char character : currentLineOfImageString){
            //cout << "Line number    "<<linenumber << "currentint" << currentLineOfImageString<< endl;
            //this passes every character into a checker to make sure its a digit
            checkifaninteger(character, linenumber);
        }
        //if that passes then add the numbers together in groups of three

        //cout << linenumber << "  line number"<<endl;
        stringstream s(currentLineOfImageString);
        int currentint = 0;
        int totalint = 0;
        while(s >> totalint){
            cout << totalint <<endl;
            numberofthreeadding(totalint);
        }
        //this while loop goes through all the contents of everyline

        linenumber++;
        //cout << s << endl;
        //cout <<currentLineOfImageString.size() << endl;
        //cout << currentLineOfImageString << "space"<<test<<"!!"<<currentLineOfImageString.size()<<endl;
        //if(test.c_str()[3] == '\n' || test.c_str()[3] == ' '){
        //}else{
        //    cout <<test.c_str()[3]<<endl;
       // }
        ///for(int x = 0; x < currentLineOfImageString.size(); x++){
            //if(test.c_str()[x] == '\n'){}else{
            //cout << test.c_str()[x] << endl;}
        //}

        //cout << filetext << "filetext";

        //cout << filetext << endl;
        }
    }
    void numberofthreeadding(int numbertoadd){
        numberof3++;
        totalofthethree = totalofthethree + numbertoadd;
        if(numberof3 == 3){
            checkingaginsthash();
            numberof3 =0;
            totalofthethree = 0;

        }

    }
    void checkingaginsthash(){
        cout << trackofcalcuatedhashesline << " line hash is" << totalofthethree <<endl;
        trackofcalcuatedhashesline++;

    }
    void OpeningchecksumsFile(){
        ifstream ImageChecksumsFile;
};
int initilizearrays(){

}

int main(int argc, char* argv[]) {
    //make sure that the input is the right number
    if(argc >= 3){
        cout << argv[3];

    }else{
        cout << "add correct input amount\n";
        //validd eli;
        //eli.var = 20;
        //eli.print();
        testingopeningfile elliot;
        elliot.OpeningImageppmFile();
        return -1;
    }
    cout << "good jobaaaaaasssz";
    cout << +argc;
    return 0;
}
};