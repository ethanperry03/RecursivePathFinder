# Cave Mapping with Recursion

## Authors
Ethan Perry

## Description
This project involves creating a recursive search algorithm in C++ to guide an autonomous vehicle through a cave system, mapping out all possible paths from the upper left corner to the lower right corner. The program reads a grid from a file, where open paths and blockages are represented by characters. The primary objective is to practice recursion and good Object-Oriented Programming (OOP) techniques, ensuring that all methods and data are encapsulated within a `cave` class.

## How to Run

1. **Compile the Program:**
    ```sh
    g++ -o cave_mapping main.cpp cave.cpp
    ```

2. **Run the Program:**
    ```sh
    ./cave_mapping
    ```

3. **Input File:**
    - Ensure the input file is a plain text file with the following format:
        ```
        R C
        Grid_Content
        ```
    - Example:
        ```
        10 10
        _XXXXXXXXX
        _____XXX_X
        X_XX_XXX_X
        _XX__XX__X
        __XX_____X
        _XXXX_XXXX
        _XXXX_XXXX
        XXXXX__XXX
        XXXXXX____
        XXXXXXXXX_
        ```
    - The first line contains two integers representing rows (R) and columns (C).
    - The grid contains ' ' for open paths and 'X' for blockages.

4. **Menu Options:**
    - `displayCave()`: Displays the original cave grid.
    - `displayPath()`: Displays the path(s) found by the vehicle.
    - `searchPath()`: Searches for paths through the cave, simulating the vehicle's journey.
    - `numDeadEnds()`: Returns the number of dead ends found in the cave.

### Sample Run
```cpp
int main () {
    cave thecave;
    cout << "Initial grid: " << endl;
    thecave.displayCave();
    cout << "Searching for path(s) through cave..." << endl;
    thecave.searchPath();
    cout << "Path(s) found: " << endl;
    thecave.displayPath();
    cout << "Dead ends: " << thecave.numDeadEnds() << endl;
    return 0;
}

