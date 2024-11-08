# Cage Box Moving Game

A simple console-based box moving game written in C++. The objective of the game is to move boxes to designated destinations on the map. This project demonstrates basic game development concepts using graphics libraries in C++.

---

## Table of Contents

- [Overview](#overview)
- [Game Mechanics](#game-mechanics)
- [Controls](#controls)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

---

## Overview

The **Cage Box Moving Game** is a puzzle game where the player controls a character to push different types of boxes to their respective destinations. The game is similar to the classic Sokoban puzzle game but introduces various box types and obstacles.

---

## Game Mechanics

- **Objective**: Move all the boxes to their designated destination points on the map.
- **Boxes**: There are three types of boxes:
  - **C Box**: Standard box.
  - **R Box**: Resistant box, may have different movement mechanics.
  - **A Box**: Advanced box, possibly with unique properties.
- **Map Elements**:
  - **Wall**: Impassable terrain.
  - **Floor**: Walkable area.
  - **Destination**: Marked spot where boxes need to be moved.
  - **Character**: The player-controlled entity.

---

## Controls

- **Movement**:
  - **Up**: `W` key
  - **Down**: `S` key
  - **Left**: `A` key
  - **Right**: `D` key
- **Other Commands**:
  - **Retry**: `R` key (restart the game)
  - **Quit**: `Q` key (exit the game)

---

## Features

- **Multiple Box Types**: Different boxes with unique behaviors.
- **Graphics**: Uses `graphics.h` for rendering game elements.
- **Sound Effects**: Background music and sound effects using `mmsystem`.
- **User Interface**: Simple prompts and messages for user interactions.
- **Collision Detection**: Prevents movement through walls and handles box pushing mechanics.

---

## Technologies Used

- **Programming Language**: C++
- **Graphics Library**: `graphics.h`
- **Sound Library**: `mmsystem.h`
- **Platform**: Windows OS (due to the use of Windows-specific headers)

---

## Getting Started

### Prerequisites

- **Operating System**: Windows
- **Compiler**: A C++ compiler that supports `graphics.h` and Windows headers (e.g., Dev-C++, Turbo C++)
- **Additional Libraries**: Ensure that `Winmm.lib` is available for sound functions.

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/cage-box-moving-game.git
   cd cage-box-moving-game
