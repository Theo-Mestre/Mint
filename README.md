# Mint

**Mint** is my first attempt at creating a game engine. I developed it during my second year of programming school in 2022. It utilizes [**SFML**](https://www.sfml-dev.org/) as the core graphics library, providing a foundation for rendering and basic media capabilities.

Mint was created to simplify the usage of **SFML** and make it more "modern." It was also an opportunity for me to explore how to organize large projects and create an easy-to-use API.

## Features

### Core Functionality
- **Rendering**: Window creation, 2D rendering.
- **Input Handling**: Support for keyboard and mouse input using SFML.
- **Asset Management**: Efficient handling of textures, fonts, shaders, and other assets.
- **Animated Sprites**: Tools for creating and managing sprite animations.
- **File Management**: Simplified file I/O operations using RAII.
- **Object Pooling**: Experimental feature for efficient object reuse (not finished).
- **UI Components**: Basic user interface elements for game development (not finished).

### Thin Abstraction Layer
Most of SFML's features have been abstracted into a thin wrapper, making them easier and more intuitive to use.

### Logging and Build System
- **spdlog**: Integrated for robust and efficient logging.
- **Premake**: Used as the build system for project configuration.

## Project Goals
Mint was designed as a learning project to:
- Understand the structure of large-scale projects.
- Take a first step into the world of game engine development.
- Create a simplified, modern interface for SFML.

While Mint is functional, it is **not** production-ready and has several known flaws, such as:
- Overuse of singletons.
- Lack of comprehensive testing.

## Status
Mint is no longer actively developed as I have moved on to my current project, [**Sapphire**](https://github.com/Theo-Mestre/Sapphire). There are no plans for future updates or a roadmap.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Theo-Mestre/mint.git
   ```
2. Build the project by running the SetupWindows.bat

## License

Mint is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

- [**SFML**](https://www.sfml-dev.org/)
- [**spdlog**](https://github.com/gabime/spdlog)
- [**Premake**](https://premake.github.io/)
