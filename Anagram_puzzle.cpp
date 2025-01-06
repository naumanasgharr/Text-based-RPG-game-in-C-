#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;

void anagramGame() {

    srand(time(0));
    cout << "When walking down a path, You hear some rustling in the bushes. You feel some roots grab your feet.";
    cout << "\nThey are going to drag you into the depths of the forest!!!!";
    cout << "\nYou try to untangle them but they are just holding on too tight. You see some glowing words appear in the sky that read:";
    cout << "\nThrough the vines and shadows cast, a puzzle holds you firm and fast, Decipher the anagram, break the grasp, or in the jungle, forever last.";
    
    string userGuess;
    string words[5] = {"forbidden", "mysterious", "enchanted", "unchanted", "wanderer"};

    int randomIndex = rand() % 5;
    string selectedWord = words[randomIndex];

    string anagram = selectedWord;
    random_shuffle(anagram.begin(), anagram.end());

    cout << "\nAnagram: " << anagram << endl;

  for (int chances = 0; chances < 3; chances++) {
        string userGuess;
        cout << "(Chance " << chances + 1 << "/3): ";
        cin >> userGuess;

        transform(userGuess.begin(), userGuess.end(), userGuess.begin(), ::tolower); //converts the user input to lower case for case insensitive comparison

        if (userGuess == selectedWord) {
            cout << "Correct! You solved the anagram." << endl;
            return;
        } else {
            cout << "Incorrect." << endl;
        }
    }

    cout << "Sorry, you couldn't guess the word. The correct word was: " << selectedWord << endl;
}

int main() {


    anagramGame();

    return 0;
}
