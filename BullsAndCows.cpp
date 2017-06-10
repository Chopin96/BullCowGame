
#include "BullsAndCows.hpp"
#include <map>
#define TMap std::map
using int32 = int;

FBullCowGame::FBullCowGame() {
    const FString WORD = "planet";
    this -> CurrentTry = 1;
    this ->HiddenWord = WORD;
    this ->bIsWon = false;
    
}

int32 FBullCowGame:: GetMaxTries() const {
    TMap<int32,int32> WordLengthToTries = {{3,5} ,{5,7},{6,8},{7,10}};
    return WordLengthToTries[(int32) HiddenWord.length()];
}
int32 FBullCowGame:: GetCurrentTry() const {return CurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const { return (int32)this-> HiddenWord.length();}


void FBullCowGame::Reset() {
    this -> CurrentTry = 1;
    this ->HiddenWord="planet";
    this -> bIsWon = false;
    return;
    
}

bool FBullCowGame::isIsogram(FString word) const{
    if(word.length()<=1) return true;
    TMap<char,bool> Letter_mark;
    for(auto letter : word){
        letter =tolower(letter);
        if (Letter_mark[letter]==true) return false;
        else Letter_mark[letter]=true;
    }
    
    return true;
}

bool FBullCowGame::isAllLowerCase(FString str) const{
    if (str.empty()) return true;
    for(auto letter:str){
        if(!islower(letter)) return false;
    }
    return true;
}

bool FBullCowGame:: IsGameWon() const {
    return this -> bIsWon;
}

WordStatus FBullCowGame:: CheckGuessValidity(std::string str) const{
    if(str.length() != this->GetHiddenWordLength()){
        return WordStatus::Wrong_length;
    }
    else if (!isIsogram(str)){
        return WordStatus::Not_isogram;
    }
    
    else if(!isAllLowerCase(str)){
        return WordStatus::Not_lowercase;
    }
    
    else return WordStatus::OK;
}


BullCowCount FBullCowGame:: SubmitGuess(FString guess){
    
    this ->CurrentTry ++;
    BullCowCount Count;
    //loop through all the letters in guess input
    for(int32 i =0; i<this ->HiddenWord.length();i++){
        for (int32 j = 0;j<this->HiddenWord.length();j++){
            if (guess[i]==this->HiddenWord[j]){
                if (i==j) Count.BullCount ++;
                else Count.CowCount++;
            }
            
        }
    
    }
    
    if (Count.BullCount == this ->GetHiddenWordLength()) {this -> bIsWon=true;}
    else {this ->bIsWon=false;}
    
    return Count ;
}
