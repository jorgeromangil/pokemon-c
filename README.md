# Pokémon C 🔴🍚

An interactive text-based Pokémon battle simulator, written entirely in C. The game allows you to view pre-loaded Pokémon with realistic stats, add your own custom Pokémon, and participate in turn-based battles featuring graphical health bars in the console.

## Features

- **Dynamic Console UI:** Features an introductory colored ASCII art title banner (using ANSI codes) and a Pokéball.
- **Initial Database:** Pre-loaded with 10 classic Pokémon of different types (Charmander, Ninetales, Quilava, Dratini, Axew, Starmie, Lapras, Slowpoke, Togetic, and Enamorus) with balanced stats for attack, defense, and health.
- **Interactive Menu:**
  1. **Show available Pokémon:** Lists all Pokémon currently in the system and displays their complete stats in a clean, aligned format.
  2. **Add new Pokémon:** Allows the user to create a custom Pokémon from scratch by inputting its name, type, and stats.
  3. **Battle:** Initiates a duel against the computer.
  4. **Exit:** Closes the game with a farewell message.
- **Complete Battle Mechanics:**
  - Interactive selection of your Pokémon and random generation of the opponent (with the option to change the opponent if you prefer).
  - Dynamic health bars drawn with asterisks (`*`) proportional to the maximum health.
  - Turn-based actions: **Attack (1)** or **Defend (0)**.
  - The opponent's AI randomly decides whether to attack or defend.
  - Realistic damage calculations:
    - If both attack, both receive the full damage of the opponent's attack.
    - If one defends and the other attacks, damage is reduced by subtracting the defender's defense stat from the attacker's attack stat.
    - If both defend, no damage is taken by either side.
  - Automatic detection of the end of the battle (Victory, Defeat, or Draw).
- **Input Validation:** Prevents invalid user inputs in menus, action selection, and Pokémon changes.

## Project Structure

The repository is organized as follows:

- `pokemon.c`: The main source code, clean, fully functional, and up to date.
- `.gitignore`: Configuration to prevent committing compiled binaries and temporary editor files.
- `archive/`: Folder containing previous development versions for historical reference:
  - `pokemonc.c`: Initial basic version with generic Charmanders and incomplete battle loops.
  - `pokemon1012.c`: Intermediate version that modularized some selection parts but left the combat simulation incomplete.

## Compilation and Execution

To compile and run the project, ensure you have a C compiler installed (such as `gcc` or `clang`).

### On Linux / macOS / WSL (Windows Subsystem for Linux)

1. Compile the source file:
   ```bash
   gcc -o pokemon pokemon.c
   ```
2. Run the game:
   ```bash
   ./pokemon
   ```

### On Windows (PowerShell / CMD with GCC installed)

1. Compile the source file:
   ```powershell
   gcc -o pokemon.exe pokemon.c
   ```
2. Run the game:
   ```powershell
   .\pokemon.exe
   ```

---

*Project developed as an exercise in structured programming in C, utilizing structures, arrays, pointers, and parameter passing by reference.*
