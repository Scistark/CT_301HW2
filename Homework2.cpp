//#include <Homework2.h>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

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
    textfile.open("checksums.txt");
    while(getline(textfile,filetext)){
        cout << filetext << endl;
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