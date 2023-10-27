#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

// Variable declarations
string codeElements[6] = {"RD", "BU", "YW", "GN", "WH", "BK"};
string randomCode[4] = {};
int chancesRemaining = 8;

// Function declarations
void generateRandomCode();
void getPlayerInput();
void validatePlayerInput(string playerInput[4]);
void evaluatePlayerInput(string playerInput[4]);

// Main function
int main() {
  // Generate random code to be broken
  generateRandomCode();
  cout << endl;

  // Prints codeElements
  cout << "Code colors: ";
  for (int i = 0; i < 6; i++) {
    cout << "[" << codeElements[i] << "]";
  }
  cout << endl << endl;

  // Defines clues for the player
  cout << "Feedback key: " << endl;
  cout << "[WH] = Right color, right position." << endl;
  cout << "[RD] = Right color, wrong position." << endl;
  cout << "[  ] = Wrong color." << endl;
  cout << endl;

  // Start core game loop.
  cout << "You have " << chancesRemaining << " attempts to break the code.\n";
  getPlayerInput();
  cout << endl;

  return 0;
}

// Function definitions

// Generates a random code
void generateRandomCode() {
  srand((unsigned) time(NULL));
  for (int i = 0; i < 6; i++) {
    int random = rand() % 6;
    randomCode[i] = codeElements[random];
  };
};

// Gathers input from the player
void getPlayerInput() {
  string playerInput[4];
  cout << "Input guess: ";
  cin >> playerInput[0] >> playerInput[1] >> playerInput[2] >> playerInput[3];
  validatePlayerInput(playerInput);
};

// Verifies clean inputs
void validatePlayerInput(string playerInput[4]) {
  for (int i = 0; i < 4; i++) {
    if (playerInput[i] == codeElements[0] || playerInput[i] == codeElements[1] || playerInput[i] == codeElements[2] || playerInput[i] == codeElements[3] || playerInput[i] == codeElements[4] || playerInput[i] == codeElements[5]) {
      continue;
    } else {
      cout << "\n***INVALID INPUT***\nPlease try again.\n";
      return getPlayerInput();
    }
  }
  return evaluatePlayerInput(playerInput);
}

// Evaluates player guesses and provides appropriate feedback
void evaluatePlayerInput(string playerInput[4]) {
  // Evaluate win condition
  if (playerInput[0] == randomCode[0] && playerInput[1] == randomCode[1] && playerInput[2] == randomCode[2] && playerInput[3] == randomCode[3]) {
    cout << "YOU WIN!";
    return;
  } else {
    // Provide clues to the player
    cout << "Feedback: ";
    for (int i = 0; i < 4; i++) {
      if (playerInput[i] == randomCode[i]) {
        cout << "[WH]";
      } else if (playerInput[i] == randomCode[0] || playerInput[i] == randomCode[1] || playerInput[i] == randomCode[2] || playerInput[i] == randomCode[3]) {
        cout << "[RD]";
      } else {
        cout << "[  ]";
      }
    }
    chancesRemaining--;
    cout << "\n\nChances remaining: " << chancesRemaining << endl;
  }
  // Evaluate lose condition
  if (chancesRemaining == 0) {
    cout << "YOU LOSE!\n";
    cout << "Solution: ";
    for (int i = 0; i < 4; i++) {
      cout << "[" << randomCode[i] << "]";
    }
    return;
  } else {
    return getPlayerInput();
  }
}