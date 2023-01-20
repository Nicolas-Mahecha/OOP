#include <iostream>
#include <Player.h>
#include <Question.h>
#include <Option.h>
#include <MiniQuestion.h>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int nQuestions = 22 ;
int nPoints = 5 ;
vector<Player*> managePlayers(int numberPlayers);
int askNumberPlayers();
int game(int numberPlayers , int nQuestions, vector<Question*> questions, vector<Player*> players);
vector<Question*> loadQuestions(int numberQuestions, vector<Option*> options);
vector<Option*> loadOptions(int nQuestions);
string checkValideAnswer( Question* q);
bool isNumber(const string& str);
int askPoints();
void deletePlayers(vector<Player*> players);
void deleteQuestions(vector<Question*> questions);
void deleteOptions(vector<Option*> options);

int main()
{
    int numberPlayers;
    vector<Option*> options;
    vector<Question*> questions;
    vector<Player*> players;
    cout << "\t\t\t\t\tWelcome to this game!!" << endl;
    cout << "\tThe rules are simple!! Play with your friends to see who answer correctly more questions.\n\tEach round of questions worth different random points ( from 1 to 6 )\n\tFirst to reach " << nPoints << " points wins!!\n\tBe careful!! The answer must be exactly as the seen options\n" << endl;
    numberPlayers = askNumberPlayers();
    players = managePlayers(numberPlayers);
    options = loadOptions(nQuestions);
    questions = loadQuestions(nQuestions, options);
    game( numberPlayers , nQuestions, questions, players);
    deletePlayers(players);
    deleteQuestions( questions);
    deleteOptions (options);
    return 0;
}

vector<Player*> managePlayers(int numberPlayers){
    string playerName;
    vector<Player*> players;
    for(int i=0 ; i < numberPlayers ; i++){
        cout << "\t\t\t\tName of the player " << i + 1 << "?" << endl;
        cin >> playerName;
        Player* p =  new Player(playerName);
        players.push_back(p);
    }
    return players;
}

vector<Question*> loadQuestions(int numberQuestions , vector<Option*> options){
    vector<Question*> questions;
    vector<Option*> newOptions;
    string question;
    ifstream inf ("Questions.txt");
    if(inf.fail()){
        cout << "There was a problem reading the questions" << endl;
    }else{
        for( int i = 0 ; i < numberQuestions ; i++){
            getline(inf, question);
            for(int j = i + i *3  ; j < 4*i +4; j++){
                newOptions.push_back(options[j]);
            }
            Question* q = new Question(question , newOptions);
            questions.push_back(q);
            newOptions.clear();
        }
        getline(inf, question);
        MiniQuestion* mini = new MiniQuestion(question);
        questions.push_back(mini);
        return questions;
    }
}
vector<Option*> loadOptions(int nQuestions){
    vector<Option*> options;
    string option;
    ifstream info ("Options.txt");
    if(info.fail()){
        cout << "There was a problem reading the questions" << endl;
    }else{
        for( int i = 0 ; i < nQuestions ; i++){
            for(int j = 0 ; j < 4; j++){
                getline(info, option);
                if(j == 0) {
                    Option* o = new Option(option, true);
                    options.push_back(o);
                } else {
                    Option* o = new Option(option, false);
                    options.push_back(o);
                }
            }
        }
    return options;
    }
}
int askNumberPlayers(){
    bool exit = false;
    string answer ;
    int numberPlayers ;
    do{
        cout << "\tHow many players are gonna play today?" << endl;
        cin >> numberPlayers ;
        if(numberPlayers >= 2 && numberPlayers <= 4 ){
            exit = true;
        }else{
            cout << "Number of players must be between 2 and 4 people" << endl;
        }
    }while(exit== false);
    return numberPlayers;
}
int game(int numberPlayers , int nQuestions, vector<Question*> questions, vector<Player*> players){
    string userAnswer;
    string realAnswer;
    vector<int> numberQ;
    int random;
    int j = 0;
    int round = 1;
    int pointsRound = 0 ;
    bool finished = false ;
    srand(time(0));
    for( int i = 0 ; i < nQuestions ; i ++){
        finished = false ;
        while(!finished){
            random = rand() % nQuestions ;
            if (find(numberQ.begin(), numberQ.end(), random) == numberQ.end()){
                numberQ.push_back(random);
                finished = true ;
            }
        }
        if( j == 0 ) {
            pointsRound = rand() % 6 + 1 ;
            cout << "\n\tROUND " << round << "!!" << " This round is worth " << pointsRound << " points!!" << endl;
        }
        cout << "\n\t\tTurn of " << players[j]->getName() << "\n" << endl;
        cout << questions[random]->getTitle() << endl;
        questions[random]->showOptions();
        realAnswer = questions[random]->getAnswer();
        cout << "\n\tWrite your answer" << endl;
        getline( cin, userAnswer);
        bool isEqual = realAnswer == userAnswer ;
        if (isEqual) {
            players[j]->setScore(players[j]->getScore() + pointsRound );
            questions[i]->print(players[i]->getName());
            questions[i]->print(pointsRound);
        }else{
            cout << "\tOhh bad luck " <<  players[j]->getName()  << "!! That was incorrect" << endl;
            cout << "\tThe correct answer was " << questions[random]->getAnswer() << "\n" << endl;
        }
        for( int k = 0 ; k < numberPlayers ; k++){
            players[k]->dispScore();
        }
        cout << endl;
        system("pause");
        if( players[j]->getScore() >= nPoints ) {
            cout << "Congratulations!! " << players[j]->getName() << " you won!!" << endl;
            questions[ nQuestions -1 ]->greetingsMessage();
            return 1;
        }
        j ++;
        if( j == numberPlayers ){
            j = 0;
            round ++;
        }
    }
}
int askPoints(){
    string answer;
    int points;
    cin >> answer ;
    do{
        cout << "How many points do you wanna play to win?" << endl;
    }while(!isNumber(answer));
    points = stoi(answer);
    return points;
}
bool isNumber(const string& str) {
    return str.find_first_not_of( "0123456789" ) == string::npos;
}
void deletePlayers(vector<Player*> players){
    for (auto p : players){
        delete(p);
    }
    cout << "Players have been deleted" << endl;
}
void deleteQuestions(vector<Question*> questions){
    for (auto q : questions){
        delete(q);
    }
    cout << "Questions have been deleted" << endl;
}
void deleteOptions(vector<Option*> options){
    for (auto o: options){
        delete(o);
    }
    cout << "Options have been deleted" << endl;
}




