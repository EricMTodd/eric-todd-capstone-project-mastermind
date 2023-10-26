#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;



const string codeElements[8] = {"RD", "BU", "YW", "GN", "WH", "BK"};
const string keyElements[2] = {"BK", "WH"};

int difficulty = 12;
int guessesRemaining = 12;

string guessHistory[12] = {};
string feedbackHistory[12] = {};

string randomCode[4] = {};
string playerGuess[4] = {};

void generateRandomCode();
void getPlayerInput();
void evaluatePlayerInput();
void provideEngineFeedback();

int main() {
  // Read from leaderbaord file, displaying usernames and scores
  // Press enter key to start a new game, or q to quit.
  // Input a player name
  // Select difficulty
  // Start timer

  // The core game loop starts here.
  // Generate random code to be broken [X]
  // Prompt for player guess [X]
  // If the guess is correct, the player wins and their score is recorded. They are sent back to the main menu.
  // If the guess is incorrect, appropriate feedback is provided to the player and 1 is subtracted from the player's remaining guesses.
  // If the player fails to break the code, the code is revealed, their score is recorded and they are sent back to the main menu.


  generateRandomCode();
  getPlayerInput();
  provideEngineFeedback();

  return 0;
}

void generateRandomCode() {
  srand((unsigned) time(NULL));
  for (int i = 0; i < 6; i++) {
    int random = rand() % 6;
    randomCode[i] = codeElements[random];
  };
};

void getPlayerInput() {
    cout << "randomCode: ";
  for (int i = 0; i < 4; i++) {
    cout << randomCode[i] << " ";
  }
  cout << endl;
  cout << "Attempt to break the code!\nYour options are: RD, BU, YW, GN, WH, and BK.\nType four color options with a space between each one to make your guess.\n\nEnter code: ";
  cin >> playerGuess[0] >> playerGuess[1] >> playerGuess[2] >> playerGuess[3];
  evaluatePlayerInput();
}

void evaluatePlayerInput() {
  for (int i = 0; i < 4; i++) {
    if (playerGuess[i] == codeElements[0]) {
      continue;
    } else if (playerGuess[i] == codeElements[1]) {
      continue;
    } else if (playerGuess[i] == codeElements[2]) {
      continue;
    } else if (playerGuess[i] == codeElements[3]) {
      continue;
    } else if (playerGuess[i] == codeElements[4]) {
      continue;
    } else if (playerGuess[i] == codeElements[5]) {
      continue;
    } else {
      cout << "\n\n***PLEASE INPUT A VALID CODE***\n\n";
      getPlayerInput();
    }
  }
  cout << endl;
}

void provideEngineFeedback() {
  for (int i = 0; i < 4; i++) {
    if (playerGuess[i] == randomCode[i]) {
      cout << "\nRight color, right position.";
    } else {
      if (playerGuess[i] == randomCode[0] || playerGuess[i] == randomCode[1] || playerGuess[i] == randomCode[2] || playerGuess[i] == randomCode[3]) {
        cout << "\nRight color, wrong position.";
      } else {
        cout << "\nWrong color.";
      }
    }
  }
  cout << endl;
}