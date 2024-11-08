# Cagebox Moving Game
[Watch the Demo Video](./cageBox.mp4)
This project is a cagebox moving game implemented in C/C++ using **graphics.h** for rendering visuals, **conio.h** for handling keyboard input, and **windows.h** for Windows API functions. You can **download and run this game locally** to experience moving boxes on a grid and solving levels by positioning them in designated areas.

## Overview

The **Cagebox Moving Game** allows players to control a character on a grid, pushing boxes to reach designated target areas. The game includes music, various game states (retry, quit, win), and visual feedback for box placement.

## Features

- **Grid-Based Movement**: Move the character around a 2D grid to push boxes into designated areas.
- **Multiple Levels**: Start with predefined configurations and progress.
- **Background Music**: Integrated background music enhances the gaming experience.
- **Game States**: Options for retry, quit, and winning the game with corresponding actions and visuals.

## Game Mechanics

The game uses a 2D array to represent the grid map where different values represent different elements:
- **Walls**: Block movement.
- **Floor**: Areas where the player can move.
- **Destination**: Target areas for boxes.
- **Player**: Controlled by the player.
- **Boxes**: Objects to push into target areas.

Each integer in the `map` array corresponds to an element:
- `0` = Wall, `1` = Floor, `2` = Destination, `3` = Player, `4, 5, 6` = Boxes of different types, `7, 8, 9` = Boxes correctly placed on destination spots.

## Controls

| Key | Action          | 
| --- | --------------- |
| `W` | Move Up         |
| `S` | Move Down       |
| `A` | Move Left       |
| `D` | Move Right      |
| `R` | Retry the Game  |
| `Q` | Quit the Game   |

## Technologies Used

- **Graphics Library** (`graphics.h`): For rendering visuals.
- **Keyboard Input** (`conio.h`): Capturing keyboard actions.
- **Audio Playback** (`mmsystem.h`): To play background music and sound effects.
- **Windows API** (`windows.h`): For additional system functionalities.

## Getting Started

### Prerequisites

- **C++ Compiler**: A compiler supporting `graphics.h` (e.g., Dev-C++ or Turbo C++).
- **Windows OS**: Required for `windows.h` and `mmsystem.h` compatibility.

### Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/cagebox-moving-game.git
   cd cagebox-moving-game
   ```
2. **Setup Graphics Library**: Ensure `graphics.h` and associated `.lib` files are available in your compiler's library path. Configure your IDE to link `Winmm.lib` for sound support.
3. **Compile and Run Locally**: Open the project in your C++ IDE, compile and run the program to start playing.

## Configuration

### Game Map

The grid map is defined in the `map` 2D array. Each integer value represents an object type. Modify the array to create custom levels.

```cpp
int map[LINE][COLUMN] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 2, 2, 1, 1, 1, 2, 2, 0, 0},
    ...
};
```

### Audio Files

Add background music files (`bgm1.mp3`, `bgm2.mp3`, etc.) in the project directory to enhance the user experience. The files are referenced directly in the code.

## Contributing

Contributions are welcome! Follow these steps to contribute:

1. **Fork the Repository**.
2. **Create a Feature Branch**:
   ```bash
   git checkout -b feature/YourFeature
   ```
3. **Commit Changes**:
   ```bash
   git commit -am 'Add new feature'
   ```
4. **Push and Submit PR**:
   ```bash
   git push origin feature/YourFeature
   ```

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- **Graphics.h Library**: For visual elements.
- **MMSYSTEM**: For audio functionality.
- **Windows API**: Provides additional controls and user interactions.

**Note**: Ensure required libraries (`graphics.h`, `conio.h`, etc.) are installed in your development environment. Replace `yourusername` with your actual GitHub username. You can **download and run this game locally** after setting up the prerequisites and following the installation instructions. If you have any questions, feel free to open an issue or contact the maintainers.
```
