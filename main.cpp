
#include <iostream>
#include <string>
#include "BullsAndCows.hpp"

FBullCowGame Game;
using FText = std::string;
using int32 = int;


void PrintIntro(){
    std::cout << "Welcome to Bulls and Cows game" << std::endl;
    std::cout << "Can you guess the " << Game.GetHiddenWordLength() << " letter isogram I am thinking of ?" <<std::endl;
}


FText GetGuess(){
    
    FText guess="";
    WordStatus Status;

       do{
    std::cout << "Try " << Game.GetCurrentTry() <<" .Enter your guess";
    std::getline(std::cin, guess);
    Status = Game.CheckGuessValidity(guess);
    switch (Status) {
        case WordStatus::Wrong_length:
            std::cout <<"Please enter a " << Game.GetHiddenWordLength() <<" letter word\n";
            break;
        case WordStatus::Not_lowercase:
            std::cout << "Please enter word in lowercase";
            break;
        case WordStatus::Not_isogram :
            std::cout << "Please enter an isogram";
            break;
        default:
            break;
            
        }
    }while(Status != WordStatus::OK);
    
    return guess;
}

bool Replay() {
    
    FText ans;
    do {
        std::cout <<"Would you like to play again, y or n? \n";
        std::cin >> ans;
    } while ( ans != "y" && ans != "n");
   
    return (ans=="y");
}

void PrintGameSummary(){
    if(Game.IsGameWon()) std::cout << "Congrats you won!\n";
        else if(!Game.IsGameWon()) std::cout << "You lost! Better luck next time!\n";
}

void PlayGame() {
    Game.Reset();
    while(!Game.IsGameWon() && Game.GetCurrentTry()<Game.GetMaxTries()){
        FText Guess = GetGuess();
        BullCowCount Count = Game.SubmitGuess(Guess);
        std::cout << " Bull : " <<Count.BullCount <<" Cows : " <<Count.CowCount <<std::endl;
    }
    PrintGameSummary();
    
}

int main(int argc, const char * argv[]) {
    bool b = false;
    
    do {
     PrintIntro();
     PlayGame();
     b = Replay();
    } while(b);
    
    return 0;
}
