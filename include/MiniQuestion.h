#ifndef MINIQUESTION_H
#define MINIQUESTION_H
#include <Question.h>

class MiniQuestion : public Question
{
    public:
        MiniQuestion( string title);
        void greetingsMessage();
    private:
        bool answerM ;
};

#endif // MINIQUESTION_H
