#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    bool CheckGuessValid(FString);
    
    EGuessStatus CheckGuessValidity(FString) const;
    FBullCowCount SubmitValidGuess(FString);
    
    void Reset();

private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    int32 HiddenWordLength;
    FString MyHiddenWord;
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
    bool bGameWon;
};
