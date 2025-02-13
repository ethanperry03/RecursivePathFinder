/** Ethan Perry - Program 4: Cave Recursion
 * Files:
 *      - cave.h: This file. Holds the class definition for the grid/cave
 *        search functionality of this program. All public methods given
 *        in the spec sheet are present and without parameters.
 *      - cave.cpp: This is the implementation of the specified cave
 *        class data created and defined by this .h file.
 *      - main.cpp: given by the project specs, nothing particularly special here.
 *
 * DESCRIPTION: This program asks the user for a input file that stores a
 * maze to search through (simulating a cave / corn maze). The program, using
 * only recursion, opens the file, stores all the grid data, then calls a
 * recursive path search method. This method finds all the valid paths through
 * the cave, recording exactly where a valid path exists. This also creates a
 * grid that stores just the paths taken through the grid. It will record all
 * the dead ends in the path, and then the original grid, just the paths, and
 * the number of dead ends is outputted to the user (dictated by the given main).
 *
 * INPUT: The main that was given is essentially all the program needs to run.
 * The only input is the input file that is prompted to store the cave grid.
 *
 * OUTPUT: The output will be the input grid displayed nicely, then just the
 * paths that are taken through the cave, and finally the number of dead ends.
 *
 * I have abided by the Wheaton College Honor Code in this work.
 */

#include <iostream>
#include "vector"
#include "fstream"
using namespace std;

#ifndef PATHFINDER_CAVE_H
#define PATHFINDER_CAVE_H

class cave {
    int row = 0;            // stores # rows from file
    int col = 0;            // stores # cols from file
    int r = 1;              // indexing for (r)ows
    int c = 1;              // indexing for (c)ols
    int deadends = 0;       // dead ends counter
    bool empty = true;      // infile flag
    ifstream infile;        // infile pointer

    vector<string> inputcave;   // stores in input cave
    vector<string> grid;        // stores the padded grid
    vector<string> justPath;    // stores just the path taken

    // recursive infile reading method
    void readInfile();
    // recursive display vector method (displays the cave/path)
    void displayVector(const vector<string>&, int);

public:
    cave();                 // constructor
    void displayCave();     // displays the input cave
    void displayPath();     // displays the path through cave
    void searchPath();      // searches for the paths
    int numDeadEnds();      // returns number of dead ends in path
};

#endif //PATHFINDER_CAVE_H