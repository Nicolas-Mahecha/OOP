#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
        Player(string name);
        virtual ~Player();
        int getScore();
        string getName();
        void dispScore();
        void setScore(int newScore);
        void setName(string newName);
    private:
        string name;
        int score = 0;
};

#endif // PLAYER_H
