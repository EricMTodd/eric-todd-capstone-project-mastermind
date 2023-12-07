// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX // 
  // Name: Eric Todd //
  // Date: 12.7.2023 //
  // Assignment: Capstone Project - Mastermind //
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX // 
// Preprocessors
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <chrono>
#include <cstring>
// Namespaces
using namespace std;
using namespace chrono;
// Variable declarations
// REQUIREMENTS 4 & 5 - Variables and arrays
string codeElements[6] = {"RD", "BU", "YW", "GN", "WH", "BK"};
string randomCode[4] = {};
string playerName;
int chancesRemaining = 8;
int timeElapsed;
int score;
string names[11];
string scores[11];
int namesIndex = 0;
int scoresIndex = 0;
// Function declarations
void generateRandomCode();
void getPlayerInput();
void validatePlayerInput(string playerInput[4]);
void evaluatePlayerInput(string playerInput[4]);
void bubbleSort();
void load();
void save();
// Main function
int main() {
  // Generate random code to be broken
  generateRandomCode();
  cout << endl;
  // Print game title
  // REQUIREMENT 3: Terminal output
  cout << "----------------" << endl;
  cout << "   MASTERMIND" << endl;
  cout << "----------------" << endl;
  cout << endl;
  // Display leaderboard
  load();
  // Get player name
  // REQUIREMENT 3: Terminal output
  cout << "Please enter your name to begin: ";
  // REQUIREMENT 3: Terminal input
  cin >> playerName;
  cout << endl << endl;
  // Rules
  // Establish goals
  // REQUIREMENT 3: Terminal output
  cout << "You are attempting to break a randomly generated 4 color code combination made up of six possible colors. These colors can be in any order, and in any number." << endl;
  // Establish input pattern
  // REQUIREMENT 3: Terminal output
  cout << "Type any 4 of the letter combinations listed below, seperated by a space. " << endl << endl;
  // Prints codeElements
  // REQUIREMENT 3: Terminal output
  cout << "Code colors: ";
  for (int i = 0; i < 6; i++) {
    cout << "[" << codeElements[i] << "]";
  }
  // REQUIREMENT 3: Terminal output
  cout << endl << endl;
  cout << "After you have input your desired guess, hit the enter key. The engine will provide feeback based on your guess in order to provide clues to the solution." << endl << endl;
  // Defines clues for the player
  // REQUIREMENT 3: Terminal output
  cout << "Feedback key: " << endl;
  cout << "[WH] = Right color, right position." << endl;
  cout << "[RD] = Right color, wrong position." << endl;
  cout << "[  ] = Wrong color." << endl;
  cout << endl;
  cout << "You will be scored after you win or lose. You want the lowest score possible. Your score is calculated based on how many attempts you made, and how long it took for you to (or fail to) break the code." << endl << endl;
  // glhf
  // REQUIREMENT 3: Terminal output
  cout << "Good luck, have fun!" << endl << endl;
  // Start timer
  // REQUIREMENT 4 - Variables
  auto start = steady_clock::now();
  // Start core game loop.
  // REQUIREMENT 3: Terminal output
  cout << "You have " << chancesRemaining << " attempts to break the code.\n";
  // REQUIREMENT 3: Terminal input
  getPlayerInput();
  // REQUIREMENT 3: Terminal output
  cout << endl;
  // Stop timer
  // REQUIREMENT 1: Algorithms - Timer for score calculation
  auto stop = steady_clock::now() - start;
  // REQUIREMENT 4 - Variables
  timeElapsed = duration_cast<milliseconds>(stop).count();
  // Assign score
  // REQUIREMENT 1: Algorithms - Score calculation
  score = (9 - chancesRemaining) * timeElapsed;
  // REQUIREMENT 3: Terminal output
  cout << "Your score is: " << score << endl << endl;
  // Sort player scores
  bubbleSort();
  // Save player score and display leaderboard ranking
  save();
  // Terminate program
  return 0;
}
// Function definitions
// Generates a random code
// REQUIREMENT 1: Algorithms - Random code generation
void generateRandomCode() {
  srand((unsigned) time(NULL));
// REQUIREMENT 7: Iteration (loops)
  for (int i = 0; i < 4; i++) {
    // REQUIREMENT 4 - Variables
    int random = rand() % 6;
    randomCode[i] = codeElements[random];
  };
};
// Gathers input from the player
// REQUIREMENT 3: Terminal input/output
void getPlayerInput() {
  // REQUIREMENT 4 - Variables  
  string playerInput[4];
  cout << "Input guess: ";
  cin >> playerInput[0] >> playerInput[1] >> playerInput[2] >> playerInput[3];
  validatePlayerInput(playerInput);
};
// Verifies clean inputs
// REQUIREMENTS 1, 3, 7, 8 & 9 - Algorithms, output, interaction, iteration (loops) and control 
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
// REQUIREMENTS 1, 3, 8 & 9 - Algorithms, output, interaction and control 
void evaluatePlayerInput(string playerInput[4]) {
  // Evaluate win condition
  if (playerInput[0] == randomCode[0] && playerInput[1] == randomCode[1] && playerInput[2] == randomCode[2] && playerInput[3] == randomCode[3]) {
    cout << "\nYOU WIN!";
    return;
  } else {
    // Provide clues to the player
    cout << "Feedback: ";
    // REQUIREMENT 7: Iteration (loops)
    for (int i = 0; i < 4; i++) {
      if (playerInput[i] == randomCode[i]) {
        cout << "[WH]";
      } else if (playerInput[i] == randomCode[0] || playerInput[i] == randomCode[1] || playerInput[i] == randomCode[2] || playerInput[i] == randomCode[3]) {
        cout << "[RD]";
      } else {
        cout << "[  ]";
      }
    }
    // REQUIREMENT 9: Control
    chancesRemaining--;
  }
  // Evaluate lose condition
  // REQUIREMENTS 1, 3, 8 & 9 - Algorithms, output, interaction and control 
  if (chancesRemaining == 0) {
    cout << "YOU LOSE!\n";
    cout << "Solution: ";
    // REQUIREMENT 7: Iteration (loops)
    for (int i = 0; i < 4; i++) {
      cout << "[" << randomCode[i] << "]";
    }
    return;
  } else {
    cout << "\n\nChances remaining: " << chancesRemaining << endl;
    return getPlayerInput();
  }
}
// Sorts leaderboard
// REQUIREMENT 1: Algorithms - Sorting Algorithm for Leaderboard
void bubbleSort() {
  // REQUIREMENT 4: Variables
  names[10] = playerName;
  scores[10] = to_string(score);
  int scoresToSort[11];
  // REQUIREMENT 7: Iteration (loops)
  for (int i = 0; i < 11; i++) {
    scoresToSort[i] = stoi(scores[i]);
  }

  // REQUIREMENT 7: Iteration (loops)
  for (int i = 0; i < 11 - 1; i++) {
    for (int j = 0; j < 11 - i - 1; j++) {
      if (scoresToSort[j] > scoresToSort[j + 1]) {
        swap(scoresToSort[j], scoresToSort[j + 1]);
        swap(names[j], names[j + 1]);
      }
    }
  }
  // REQUIREMENT 7: Iteration (loops)
  for (int i = 0; i < 11; i++) {
    scores[i] = to_string(scoresToSort[i]);
  }
  return;
}
// Loads leaderboard
// REQUIREMENT 6: File I/O
void load() {
  // REQUIREMENT 4 - Variables
  fstream file;
  string line;
  file.open("leaderboard.txt", ios::in);
  // REQUIREMENT 7 & 9: Iteration (loops) and control
  if (file.is_open()) {
    for (int i = 0; i < 20; i++) {
      getline(file, line);
      if (i == 0 || i % 2 == 0) {
        names[namesIndex] = line;
        namesIndex++;
      } else {
        scores[scoresIndex] = line;
        scoresIndex++;
      }
    }
  } else {
    // REQUIREMENT 1: Algorithms - File and data generation for file I/O
    cout << "Performing first time setup..." << endl << endl;
    file.open("leaderboard.txt", ios::out);
    // REQUIREMENT 7 & 9: Iteration (loops) and control
    if (file.is_open()) {
      for (int i = 0; i < 20; i++) {
        if (i == 0 || i % 2 == 0) {
          file << "EMPTY" << endl;
          names[namesIndex] = "EMPTY";
          namesIndex++;
        } else {
          file << "999999999" << endl;
          scores[scoresIndex] = "999999999";
          scoresIndex++;
        }
      }
    }
  }
  file.close();
  for (int i = 0; i < 10; i++) {
    cout << i + 1 << ". " << names[i] << "---" << scores[i] << endl;
  }
  cout << endl;
  return;
}
// Saves leaderboard
// REQUIREMENT 6: File I/O
void save() {
  fstream file;

  file.open("leaderboard.txt", ios::out);
  if (file.is_open()) {
    for (int i = 0; i < 11; i++) {
      file << names[i] << endl << scores[i] << endl;
    }
  }
  file.close();
  for (int i = 0; i < 10; i++) {
    cout << i + 1 << ". " << names[i] << "---" << scores[i] << endl;
  }
  cout << endl;
  return;
}