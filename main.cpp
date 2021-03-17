
#include <iostream>
#include <string>
#include "snowman.hpp"

using namespace ariel;
using namespace std;

int main()
{
    std::cout << "Lets see how the snowman library works!" << endl;
    std::cout << "To render a snowman, call the snowman function which gets an integer of 8 digits between 1 and 4 as an parameter " << endl;
    std::cout << "The function works as follows:" << endl;
    std::cout << "let ABCDEFGH be digits between 1 and 4,\nevery digit in the series represents a choice for a section in the snowman" << endl;
    std::cout << "A for the hat,\nB for the nose,\nC for the left eye,\nD for the right eye,\nE for the left arm,\nF for the right arm,\nG for the torso,H for the base    " << endl;
    std::cout << "For example, for the input 11111111 we'll get the following snowman:" << endl;
    std::cout << snowman(11111111) << endl;
    std::cout << "Let's see another example, watch this russian snowman getting the Sputnik vaccine to his shouler:" << endl;
    std::cout << snowman(42224322) << endl;
    std::cout << "There are more than 60,000 possible combinations, just go ahead and try!" << endl;
    std::cout << "Note: The input of the function must be 8-digit-long, each digit must be between 1 and 4. Otherwise the function will throw an error." << endl;
}