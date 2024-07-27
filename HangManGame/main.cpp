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

int main() {
    
    // calling main game function
    hangmanGame();
    
    return 0;
}

// gets random word from array list and returns it
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

// displays the word as '_' when no guess has been made or it is wrong
void displayWord(std::string wordToGuess, char letter) {
    
    char s;
    unsigned long length = wordToGuess.length();

    for (int i = 0; i < length; i++)
    {
        int result = linearSearch(wordToGuess, letter);
        
        do
        {
            s = length;
            s = '_';
            
            if (result > 0) 
            {
                if (letter == wordToGuess.at(i))
                {
                    s = letter;
                }
            }
            std::cout << s << ' ';
        } while (wordToGuess.back() == letter);
    }
    std::cout << std::endl;
}

// main gain function calling other functions when appropriate
void hangmanGame(){
    
    std::cout << "--WELCOME TO HANGMAN--\n" << "(CASE SENSITIVE!! - use lowercase typing)\n\n";
    
    std::string wordToGuess;
    char userInput;
    wordToGuess = createWord();
    std::cout << wordToGuess << std::endl;
    bool guess = false;
    
    while (!guess)
    {
        std::cout << "WORD: ";
        displayWord(wordToGuess, userInput);
        
        std::cout << "\n";
        
        std::cout << "Guess a letter: ";
        std::cin >> userInput;
        
        // checking to make sure user finishes typing the word until its last letter
        if (wordToGuess.back() == userInput)
        {
            guess = true;
        }
    }
    
    std::cout << "CORRECT! WORD IS '" << wordToGuess << "'" << std::endl;
    
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
