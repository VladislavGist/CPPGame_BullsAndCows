#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PlayGame();
bool RepeatGame();

FBullCowGame BSGame;

int main() {
    do {
        PrintIntro();
        PlayGame();
    } while(RepeatGame());
    
    return 0;
}

void PrintIntro() {
    constexpr int WORLD_LENGTH = 5;
    
    std::cout << "Добро пожаловать в игру Быки и коровы!";
    std::cout << std::endl;
    std::cout << "Сможете угадать слово из " << WORLD_LENGTH << " букв?";
    std::cout << std::endl;
    
    return;
}

void PlayGame() {
    BSGame.Reset();
    int MaxTries = BSGame.GetMaxTries();
    
    std::cout << "Максимум попыток: " << MaxTries << std::endl;
    
    for (int32 i = 1; i <= MaxTries; i++) {
        FText Guess = GetGuess();
        
        FBullCowCount BullCowCount = BSGame.SubmitGuess(Guess);
        
        std::cout << "Быки = " << BullCowCount.Bulls;
        std::cout << ". Коровы = " << BullCowCount.Cows;
        std::cout << std::endl;
    }
    
    return;
}

FText GetGuess() {
    FText Guess = "";
    int32 CurrentTry = BSGame.GetCurrentTry();
    
    std::cout << "Попытка: " << CurrentTry << ". Введите слово: ";
    getline(std::cin, Guess);
    
    return Guess;
}

bool RepeatGame() {
    FText UserResponse = "";
    
    std::cout << "Хотите сыграть еще? (Да/Нет): ";
    std::cin >> UserResponse;
    
    if (UserResponse == "Да" || UserResponse == "да") return true;
    return false;
}
