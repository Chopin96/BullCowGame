
#include <string>
using FString = std::string;
using int32 = int;

struct BullCowCount {
    int32 BullCount =0;
    int32 CowCount = 0;
};

enum class WordStatus{
    OK,
    Not_isogram,
    Wrong_length,
    Not_lowercase,
    
};




class FBullCowGame{
public:
    FBullCowGame();
    void Reset();
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    WordStatus CheckGuessValidity(FString) const;
    //returns the number of Bulls and Cows, increment try # counter assuming valid guess input.
    BullCowCount SubmitGuess(FString);
    
private:
    int32 CurrentTry;
    int32 MaxTries;
    FString HiddenWord;
    bool bIsWon;
    bool isIsogram(FString) const;
    bool isAllLowerCase(FString) const;
};


