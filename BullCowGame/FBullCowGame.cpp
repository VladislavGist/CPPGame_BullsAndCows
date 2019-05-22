#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset() {
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameWon = false;
    
    return;
}

bool FBullCowGame::CheckGuessValid(std::string) { return false; }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = GetHiddenWordLength();
    
    for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
        for (int32 GChar = 0; GChar < WordLength; GChar++) {
            if (Guess[GChar] == MyHiddenWord[MHWChar]) {
                if (MHWChar == GChar) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    if (BullCowCount.Bulls == WordLength) {
        bGameWon = true;
    } else {
        bGameWon = false;
    }
    
    return BullCowCount;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    if (!IsIsogram(Guess)) {
        return EGuessStatus::Not_Isogram;
    } else if (!IsLowercase(Guess)) {
        return EGuessStatus::Not_Lowercase;
    } else if (Guess.length() != GetHiddenWordLength()) {
        return EGuessStatus::Wrong_Length;
    } else {
        return EGuessStatus::OK;
    }
}

bool FBullCowGame::IsIsogram(FString Word) const {
    TMap<char, bool> LetterSeen;
    
    if (Word.length() <= 1) {
        return true;
    }
    
    for (auto Letter : Word) {
        Letter = tolower(Letter);
        
        if (LetterSeen[Letter]) {
            return false;
        } else {
            LetterSeen[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
    TMap<char, bool> LetterSeen;
    int32 WordLength = Word.length();
    
    if (WordLength <= 1) {
        return false;
    } else {
        for (auto Letter : Word) {
            if (!islower(Letter)) {
                return false;
            } else {
                return true;
            }
        }
    }
    
    return true;
}

