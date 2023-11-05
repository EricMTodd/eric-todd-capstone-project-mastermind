# eric-todd-capstone-project-mastermind

## Notes:
### CLASS REQUIREMENT
- Three major control structures exist. Input validation, win/lose conditions, and engine feeback.
- Repetitive actions such as user input and input evaluation will be broken down into functions.

1. The player inputs data.
2. Checks will be made to verify clean input data. This will prevent runtime errors and penalize the player by making them take longer to break the code.
3. If the data is clean, the input is evaluated.
4. If the win condition is met, the player is scored and the game ends.
5. If the win condition is not met, the lose condition is checked.
6. If the lose condition is met, the player is scored and the game ends.
7. If the lose condition is not met, feedback is provided to player.
8. Return to step 1.

## Tasks:
- Implement file I/O
  - Determine a data scructure for player's and scores. (Likely class instantion).
  - Leaderboard will be an array with only 10 available spots.
  - New players are treated as an 11th option for the leaderboard[10], and after scoring are sorted into the leaderboard[10].

  - File will be read and data loaded into a variable.
  - After the game finishes, the player is sorted into the high scores array and new bottom score is removed if the new player achieves a place on the board.
  - The variable is written to the leaderboard file.
  - Leaderboard will have to be an array of player objects, sorted in descending order by score.

  - Figure out how to write an array of objects to a file. Combine array io techniques with object io techniques. Something about whitespace... Check that youtube video again: https://www.youtube.com/watch?v=SPfJ856eEN4&t=395s
  - Another possible solution is using vectors, illustrated here: https://stackoverflow.com/questions/37532631/read-class-objects-from-file-c
  - Since strings are objects themselves, when they are read from a file, they're actually pointing to a place in memory. When the new file executes, that place no longer exists which is the cause for the segmentation fault. Look into using dynamic char arrays to solve this issue.
  - Loop over a string: https://www.youtube.com/watch?v=s7w-q2RoIFg