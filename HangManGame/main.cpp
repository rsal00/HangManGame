//
//  main.cpp
//  HangManGame
//
//  Created by Ruben Salazar on 7/27/24.
//

#include <iostream>
#include <vector>

// function prototypes
std::string createWord();
void displayWord(std::string, char);
void hangmanGame();
int linearSearch(std::string, char);

std::string currentDisplay;

int main() {
    
    // calling main game function
    hangmanGame();
    
    return 0;
}

// gets random word from array list and returns it
std::string createWord() {
    const int WORD_AMOUNT = 20;
    
    std::string words[WORD_AMOUNT] = { "north", "south", "east", "west", "wave",
                                       "weight", "guitar", "piano", "keyboard", "fortunate",
                                       "phone", "honesty", "corridor", "table", "desk",
                                       "outside", "university", "monster", "universe", "audio"};
    
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

// displays the word as '_' when no guess has been made or guees is wrong
void displayWord(std::string wordToGuess, char letter) {
    
    unsigned long length = wordToGuess.length();

    for (int i = 0; i < length; i++)
    {
        if (wordToGuess.at(i) == letter)
        {
            currentDisplay[i] = letter;
        }
    }
    
    for (auto c : currentDisplay)
    {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
}

// algorithm to find a letter in a word with a user inputted char value
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

// main game function calling other functions when appropriate
void hangmanGame(){
    
    std::cout << "--WELCOME TO HANGMAN--\n" << "(CASE SENSITIVE!! - use lowercase typing)\n\n";
    
    std::string wordToGuess;
    wordToGuess = createWord();
    
    long length = wordToGuess.length();
    currentDisplay = std::string(length, '_');
    
    char userInput;
    bool guess = false;
    
    while (!guess)
    {
        std::cout << "WORD: ";
        displayWord(wordToGuess, userInput);
        
        std::cout << "\n";
        
        std::cout << "Guess a letter: ";
        std::cin >> userInput;
        
        for (size_t i = 0; i < length; ++i)
        {
            if (wordToGuess[i] == userInput)
            {
                currentDisplay[i] = userInput;
            }
        }
        
        if (currentDisplay == wordToGuess)
        {
            guess = true;
        }
        
    }
    
    std::cout << "CORRECT! WORD IS '" << wordToGuess << "'" << std::endl;
}
