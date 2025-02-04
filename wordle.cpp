/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() {
    std::vector<int> secret = {};
    int counter = 0; 
    while (counter < 4)
    {
        int val = rand() % 10;
        secret.push_back(val);
        counter = counter + 1;
    }
    return secret;   
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
    int secretIndex = 0;
    int guessIndex = 0;
    std::vector<std::string> hint = {};
    while (guessIndex < 4)
    {
        if (guess[guessIndex]== secret[secretIndex])
        {
            hint.push_back("O");
        }
        else
        {
            hint.push_back("X");
        }
        secretIndex = secretIndex + 1;
        guessIndex = guessIndex + 1;
        return hint;
    }




    return hint;    
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
    if (guess == secret)
    {
        return true;
    }
    return false;    
}

int main()
{
    srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    
    int secret_code_length = 4;
    int num_guesses = 0;
    

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess)) 
    {
        std::cout << "\nEnter your guess: " << std::endl;
        hint = {};   
        int counter = 0;
        user_guess.clear();

        while (counter < secret_code_length)
        {
         int input;
         std::cin >> input;
         user_guess.push_back(input);
         counter = counter + 1;
        }



        display(user_guess);
        hint = getHint(secret_code, user_guess);
        std::cout << hint;
        num_guesses = num_guesses + 1;

    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
