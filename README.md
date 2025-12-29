# MyGreen
This is an old project for University of Padua OOP course (2023). The original version utilized a custom container developed to meet specific academic requirements; this version has been refactored to use the standard C++ std::map for better efficiency and maintainability.
MyGreen is a C++/Qt application designed to create and manage a personalized digital encyclopedia for green spaces like gardens, parks, or nature reserves. Inspired by the Pokédex and academic natural science guides, it allows users to track six categories of organisms: amphibians, birds, mammals, reptiles, herbaceous plants, and trees.

Each entry features a specialized layout including taxonomy, IUCN conservation status, and descriptions. Animal profiles include audio clips of their calls, while plant profiles showcase specific details like leaves, flowers, and fruits. The software includes a multi-filter search system (name, type, habitat, status) to easily navigate the collected data.

## Installation & Build
To build and run this application, you need a C++ compiler (GCC/Clang) and the **Qt 6 SDK** installed on your system.
The software utilizes the `QSoundEffect` class from the **Qt Multimedia** library for audio features. Navigate to the `myGreen` directory and run:

```bash
sudo apt update
sudo apt install qt6-multimedia-dev
qmake
make
./myGreen