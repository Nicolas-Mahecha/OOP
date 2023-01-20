#include "Question.h"
#include "Option.h"
#include <string>
#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

Question::Question(string title , vector<Option*> options)
{
    this->title = title;
    this->options = options;
    hecho = false;
}
string Question::getTitle(){
    return title;
}
string Question::getAnswer(){
    string answer;
    for(auto i = 0 ; i < options.size() ; i++ ){
        if(options[i]->getCorrect()){
            return options[i]->getTitle();
        }
    }
    return answer;
}
void Question::showOptions(){
     int random;
     vector<int> numbers;
     bool finished = false;
     while ( !finished){
        random = rand() % 4 ;
        if(find(numbers.begin(), numbers.end(), random) == numbers.end()){
            numbers.push_back(random);
            cout << "\t" << options[random]->getTitle() << endl;
            if(numbers.size() == 4){
                    finished = true;
            }
        }
    }
}
vector<Option*> Question::getOptions(){
    return options;
}
bool Question::isItDone(){
    return hecho;
}
void Question::done(){
    hecho = true;
}
void Question::print (int num){
    cout << "\tYou won " << num << " points!!" << endl;
}
void Question::print (string s){
    cout << "\tNice job "  <<  s   << "!! That was the correct answer" << endl;
}
void Question::greetingsMessage(){}
