#include "FBullCowGame.h"
#include <iostream>

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
    Reset();
}

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "ant";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    
    return;
}

bool FBullCowGame::CheckGuessValid(std::string) { 
    return false;
}

bool FBullCowGame::IsGameWon() const { 
    return false;
}

int32 FBullCowGame::GetMaxTries() const {
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const { 
    return MyCurrentTry;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 HiddenWordLength = MyHiddenWord.length();
    
    for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
        for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
            if (Guess[GChar] == MyHiddenWord[MHWChar]) {
                if (MHWChar == GChar) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}

