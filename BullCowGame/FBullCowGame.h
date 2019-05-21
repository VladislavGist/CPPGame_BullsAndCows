#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValid(FString);
    FBullCowCount SubmitGuess(FString);

private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};