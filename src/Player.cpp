#include "Player.h"
#include <string>
using namespace std;

Player::Player(string name )
{
    this->name = name;
}
Player::~Player(){}
void Player::setScore (int newScore){
    score=newScore;
}
int Player::getScore(){
    return score;
}
void Player::setName(string newName){
    name = newName;
}
string Player::getName(){
    return name;
}
void Player::dispScore(){
    cout << "\t-The score of " << name << " is " << score <<  endl;
}

