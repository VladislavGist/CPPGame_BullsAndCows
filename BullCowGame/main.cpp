#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
bool RepeatGame();
FText GetValidGuess();
int32 GetHiddenWordLength();

FBullCowGame BSGame;

int main() {
    do {
        PrintIntro();
        PlayGame();
    } while(RepeatGame());
    
    return 0;
}

void PrintIntro() {
    int32 HiddenWordLength = BSGame.GetHiddenWordLength();
    
    std::cout << "Добро пожаловать в игру Быки и коровы!";
    std::cout << std::endl;
    std::cout << "Сможете угадать слово из " << HiddenWordLength << " букв?";
    std::cout << std::endl;
    
    return;
}

void PlayGame() {
    BSGame.Reset();
    int MaxTries = BSGame.GetMaxTries();
    
    while(!BSGame.IsGameWon() && BSGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BSGame.SubmitValidGuess(Guess);
        
        std::cout << "Быки = " << BullCowCount.Bulls;
        std::cout << ". Коровы = " << BullCowCount.Cows << "\n\n";
    }
    
    PrintGameSummary();
    return;
}

FText GetValidGuess() {
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FString GuessResult;
    
    do {
        FText Guess = "";
        int32 CurrentTry = BSGame.GetCurrentTry();
        
        std::cout << "Попытка: " << CurrentTry << ". Введите слово: ";
        getline(std::cin, Guess);
        
        Status = BSGame.CheckGuessValidity(Guess);
        
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout
                    << "Не совпадает длина слова. Должно быть "
                    << BSGame.GetHiddenWordLength()
                    << " символов.";
                break;
                
            case EGuessStatus::Not_Lowercase:
                std::cout
                    << "Введите слово в нижнем регистре";
                break;
                
            case EGuessStatus::Not_Isogram:
                std::cout
                    << "Введите слово без повторяющихся букв";
                break;
                
            default:
                GuessResult = Guess;
        }
         std::cout << std::endl;
    } while(Status != EGuessStatus::OK);
    
    return GuessResult;
}

bool RepeatGame() {
    FText UserResponse = "";
    
    std::cout << "Хотите сыграть еще? (Да/Нет): ";
    std::cin >> UserResponse;
    
    if (UserResponse == "Да" || UserResponse == "да") return true;
    return false;
}

void PrintGameSummary() {
    if (BSGame.IsGameWon()) {
        std::cout << "Вы выиграли\n";
    } else {
        std::cout << "В следующий раз вам повезет больше.\n";
    }
}
