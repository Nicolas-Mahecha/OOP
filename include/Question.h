#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <list>
#include <map>
#include <vector>
#include "Option.h"
using namespace std;

class Question
{
    public:
        Question(string title , vector<Option*> options);
        string getTitle();
        string getAnswer();
        void showOptions();
        vector<Option*> getOptions();
        bool isItDone();
        void done();
        void print (int num);
        void print (string s);
        virtual void greetingsMessage();
    protected:
        string answer;
        string title;
        vector<Option*> options;
        bool hecho;
};

#endif // QUESTION_H

