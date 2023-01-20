#ifndef OPTION_H
#define OPTION_H
#include <string>
using namespace std;

class Option
{
    public:
        Option(string title, bool correct);
        virtual ~Option();
        string getTitle();
        bool getCorrect();
    private:
        string title;
        bool correct;
};

#endif // OPTION_H
