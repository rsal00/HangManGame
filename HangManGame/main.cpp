//
//  main.cpp
//  HangManGame
//
//  Created by Ruben Salazar on 7/27/24.
//

#include <iostream>

std::string createWord();
void displayWord(std::string, char);
void hangmanGame();
int linearSearch(std::string, char);

int main() {
    
    hangmanGame();
    
    
    return 0;
}

std::string createWord() {
    const int WORD_AMOUNT = 10;
    
    std::string words[WORD_AMOUNT] = { "north", "south", "east", "west", "wave",
                                       "weight", "guitar", "piano", "keyboard", "fortunate" };
    
    std::string randomWord;
    bool hasWord = false;
    
    srand(static_cast<unsigned int>(time(NULL)));
    int random = (rand() % WORD_AMOUNT);
    
    while (!hasWord)
    {
        randomWord = words[random];
        hasWord = true;
    }
    return randomWord;
}

void displayWord(std::string wordToGuess, char letter) {
    
    char s;
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        int result = linearSearch(wordToGuess, letter);
        unsigned long character = wordToGuess.length();
        
        s = character;
        s = '_';
        
        if (result > 0) {
            if (letter == wordToGuess.at(i))
            {
                s = letter;
            }
        }

        std::cout << s << ' ';
    }
    
    std::cout << std::endl;
}

void hangmanGame(){
    
    std::cout << "--WELCOME TO HANGMAN--\n" << "(CASE SENSITIVE!! - use lowercase typing)\n\n";
    
    std::string wordToGuess;
    char userInput;
    wordToGuess = createWord();
    std::cout << wordToGuess << std::endl;
    
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        std::cout << "WORD: ";
        displayWord(wordToGuess, userInput);
        
        std::cout << "\n";
        
        std::cout << "Guess a letter: ";
        std::cin >> userInput;
    }
//    int result = linearSearch(wordToGuess, userInput);
//    
//    if (result > 0)
//    {
//        std::cout << "Correct!\n";
//    }
//    else{
//        std::cout << "Wrong!\n";
//    }
}

int linearSearch(std::string word, char value) {
    
    long size = word.length();
    
    for (int i = 0; i < size; i++)
    {
        if (value == word.at(i))
        {
            return 1;
        }
    }
    return -1;
}

