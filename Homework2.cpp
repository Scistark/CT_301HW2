//#include <Homework2.h>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <sstream>

class validd {
    public:
    int var;
    void print(){
        cout << "Hello\n";
    }
};
class testingopeningfile {
    public:
    void Testingopeningafile(){
    string filetext;
    ifstream textfile;
    string currentline;
    textfile.open("Test.ppm");
    //this while loop interates through all the lines
    while(getline(textfile,currentline)){
        string test = currentline.substr(0,currentline.size());
        //cout <<currentline.size() << endl;
        //cout << currentline << "space"<<test<<"!!"<<currentline.size()<<endl;
        if(test.c_str()[3] == '\n' || test.c_str()[3] == ' '){
        }else{
            cout <<test.c_str()[3]<<endl;
        }
        //for(int x = 0; x < currentline.size(); x++){
            //if(test.c_str()[x] == '\n'){}else{
            //cout << test.c_str()[x] << endl;}
        //}

        //cout << filetext << "filetext";

        //cout << filetext << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    //make sure that the input is the right number
    if(argc >= 3){
        cout << argv[3];

    }else{
        cout << "add correct input amount\n";
        validd eli;
        eli.var = 20;
        eli.print();
        testingopeningfile elliot;
        elliot.Testingopeningafile();
        return -1;
    }
    cout << "good jobaaaaaasssz";
    cout << +argc;
    return 0;
}