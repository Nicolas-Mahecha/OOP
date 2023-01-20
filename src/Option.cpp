#include "Option.h"

Option::Option(string title, bool correct)
{
    this->correct = correct;
    this->title = title;
}
 string Option::getTitle(){
    return title;
}
bool Option::getCorrect(){
    return correct;
}
Option::~Option()
{
    //dtor
}
