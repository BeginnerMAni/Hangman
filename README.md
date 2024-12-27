# Hangman Game

## Overview
This project is a C++ implementation of the classic **Hangman** game. Players must guess a word by suggesting letters within a limited number of attempts. The game includes multiple difficulty levels and personalized user experiences.

## Features
- **ASCII Art:** The game displays dynamic Hangman ASCII art to enhance the gaming experience.
- **Difficulty Levels:** Players can choose between Easy, Medium, and Hard levels, with varying rules and hints.
- **Hint System:** Hints are provided in Easy and Medium levels to assist the player.
- **Score Tracking:** Tracks the player's score based on performance and difficulty.
- **User Login System:** Welcomes returning users and stores new user profiles in an external file.
- **Dynamic Word Selection:** Words are randomly selected from a large pool for varied gameplay.

## Requirements
- **Operating System:** Windows (uses `windows.h` for console-specific features).
- **Compiler:** A C++ compiler (e.g., MinGW, Visual Studio).
- **File I/O:** The game reads and writes user data to `users.txt`.

## How to Run
1. **Clone the repository** or download the project files.
2. Ensure the following files are in the same directory:
   - `main.cpp`: The C++ source code.
   - `users.txt`: A file to store and manage user profiles.
3. Compile the code using a C++ compiler, e.g.:
   ```bash
   g++ main.cpp -o hangman
   ```
4. Run the compiled program:
   ```bash
   ./hangman
   ```

## Gameplay Instructions
1. **Login:** Enter your name to login. Returning users are greeted personally.
2. **Main Menu:**
   - Start the game by pressing `1`.
   - Change the difficulty by pressing `2`.
   - View game instructions by pressing `3`.
   - Exit the game by pressing `4`.
3. **Guessing the Word:**
   - Enter one letter at a time to guess the word.
   - Hints are available for Easy and Medium levels.
   - Avoid exceeding the maximum allowed guesses to prevent the Hangman from completing.
4. **Difficulty Levels:**
   - Easy: Maximum guesses with hints available early.
   - Medium: Fewer guesses with hints available later.
   - Hard: Minimum guesses and no hints.
5. **Winning and Losing:**
   - Win by guessing the word completely before running out of attempts.
   - Lose if the Hangman figure is completed.

## File Description
- **`main.cpp`:** The core source file containing the game's logic, user interactions, and graphics.
- **`users.txt`:** Stores usernames for the login system.

## Example Gameplay
- **Input:**
  - Difficulty: Easy
  - Guess: Letters such as `a`, `e`, `s`.
- **Output:**
  - Feedback on guesses (Correct/Incorrect).
  - ASCII art reflecting the Hangman’s state.
  - Hint (if applicable).

## Future Improvements
- Adding support for multiplayer.
- Cross-platform compatibility by removing `windows.h` dependencies.
- Expanding the word list.

## License
This project is open source and distributed under the MIT License.

## Author
This project is designed as a CP semester project, providing a fun and educational way to practice programming skills.

