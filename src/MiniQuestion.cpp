#include "MiniQuestion.h"
#include <iostream>
using namespace std;

MiniQuestion::MiniQuestion(string title ) : Question( title,options) {}
void MiniQuestion::greetingsMessage(){
    string userAnswer;
    cout << "Hola" << endl;
    cout << title << endl;
    cin >> userAnswer ;
    bool isEq = "Yes" == userAnswer ;
    if (isEq){
        cout << "\tThank you we liked playing with you too!!" << endl;
    }else{
        cout << "\tWe are sorry to hear that!! We will try better in the next game" << endl;
    }
}

