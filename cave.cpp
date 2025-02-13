#include <iostream>
#include "vector"
#include "cave.h"
#include "string"
using namespace std;

/* Cave Constructor
 * This is the constructor method to the class that will prompt for
 * a user input file of a cave grid and store that into a class data member
 * vector of strings called inputcave. It then calls an infile method that
 * recursively reads in all the lines of the file.
 * PRE: No object exists.
 * POST: Cave class instance exists with the grid data member vectors storing the
 * user input data file and rows/cols data members storing header from input file.
 */
cave::cave() {
    // get infile stirng name
    string name;
    cout << "Enter infile name: ";
    getline(cin, name);

    // infile pointer (data member) opening the user file
    infile.open(name);

    // get rows and cols and store them
    infile >> row >> col;

    // for grid padding
    string padding(col+2, 'X');
    // push the padding onto the top of the vector
    grid.push_back(padding);

    // temp string gets the rest of the row/col line and start the recursion
    string temp;
    getline(infile, temp);
    // call the recursive method to read in the file
    readInfile();

    // grid padding on the bottom
    grid.push_back(padding);

    // close the infile pointer off
    infile.close();
}

/* readInFile
 * This is the recursive method that reads in all of the lines from the input file.
 * The method checks if the line you just got was valid. If yes, enter the data into
 * the correct vectors for later manipulation. If no, that means the file is at the end
 * so pop the recursion. If the first input line is not valid, the 'empty' bool is never
 * changed to false and the else if (empty) becomes true, ending the input loop.
 * PRE: The input file only has the rows and cols read in. No other data has been accessed.
 * POST: All the input file lines are read in, stored in the vectors, and when the recursion
 * ends, the methods goes back to the constructor to close the infile pointer. It also
 * handles invalid files by throwing an error.
 */
void cave::readInfile() {
    // get the current line from the input file
    string curLine;
    getline(infile, curLine);

    // if the file is still valid, store the data appropriately
    if (infile) {
        // since there was at least one valid line, empty flag is false
        // and no terminating error message is needed for an invalid file
        empty = false;

        // add to original cave vector
        inputcave.push_back(curLine);

        // create blank for the paths later
        string blanks(curLine.size(), ' ');
        justPath.push_back(blanks);

        // pad the line with 'X' for actual grid
        curLine = 'X' + curLine + 'X';
        grid.push_back(curLine);

        // recursive call
        readInfile();
    }
    // else if you have an invalid file, stop the program
    else if (empty) {
        cerr << "Invalid File.";
        exit(-1);
    }
}

/* searchPath
 * This is the meat of the program. The method searched through the grid, finding
 * valid paths to travel down, and counting the number of dead ends reached. As it
 * searches, it also starts to build the justPath vector that stores just the path
 * it is traveling. Each call starts with a 'deads' bool that is true assuming you
 * find no valid next step. If is it true by the end, you are at a dead end.
 * Else, you will have hit a recursive call under one of the four if statements
 * (Down, Right, Up, Left). It also checks if you are at the bottom right, which
 * will not count as a dead end, but rather the light at the end of the cave.
 * PRE: The cave vectors exist with no searching yet.
 * POST: All the valid path tiles have been traversed, the number of dead ends have
 * been counted, and the appropriate vectors store the data that will be outputted
 * showing the correct traversal of the maze.
 */
void cave::searchPath() {
    // initialize local dead end flag
    bool deads = true;

    // make the current place you are at a 'O' since it was valid
    grid[r][c] = 'O';

    // draw onto the final path (x-1 since r and c started at 1)
    justPath[r-1][c-1] = 'O';

    /** each search method call increments the class data indexing for row or col
     * first so that no parameters need to be passed. When the recursive call
     * returns, the respective indexing unit is then decremented. If you pass
     * under an if (not at a dead end) the 'deads' flag becomes false **/

    /// DOWN
    if (grid[r + 1][c] == '_') {
        r+=1;
        searchPath();
        r-=1;
        deads = false;
    }

    /// RIGHT
    if (grid[r][c + 1] == '_'){
        c+=1;
        searchPath();
        c-=1;
        deads = false;
    }

    /// UP
    if (grid[r - 1][c] == '_') {
        r-=1;
        searchPath();
        r+=1;
        deads = false;
    }

    /// LEFT
    if (grid[r][c - 1] == '_') {
        c-=1;
        searchPath();
        c+=1;
        deads = false;
    }

    // if deads is true, increment the deadend counter
    if(deads) {
        // put a 'D' at the dead end
        justPath[r-1][c-1] = 'D';
        deadends++;
    }

    // if you are at the bottom rigth terminal, decrement the counter
    if (r == row && c == col) {
        // put an 'E' at the end location
        justPath[r-1][c-1] = 'E';
        deadends--;
    }
}

/* displayVector
 * This method recursively passes a vector of strings to output it in a
 * nice format. It also has a counter of where you are in the vector
 * so that it can stop when it reaches the last line. This method is
 * equivalent to a for loop to output an array.
 * vec: This is the reference to the vector that is being outputted.
 * place: This is the iterator through the vector and creates the stopping condition.
 * PRE: The vector being passed is not outputted,
 * POST: The vector that was passed is outputted and aligned to the user.
 */
void cave::displayVector(const vector<string>& vec, int place) {
    // while you are in range of the vector
    if (place < vec.size()) {
        // cout the current line
        cout << vec[place] << endl;
        // recursive call for place+1
        displayVector(vec, place+1);
    }
}

/* displayCave
 * This displays the original input cave using the recursive displayVector method.
 * PRE: No output.
 * POST: Input cave is outputted to the user.
 */
void cave::displayCave() {
    // recursive call to displayVector
    displayVector(inputcave, 0);
}

/* displayPath
 * This will display just the path taken through the maze. It will show
 * all the valid paths that were accessible as well as the End and Deadends
 * PRE: no output.
 * POST: Path is displayed to the user
 */
void cave::displayPath() {
    // recursive call to displayVector
    displayVector(justPath, 0);
}

/* numDeadEnds
 * This returns the number of dead ends to the user since
 * dead ends is a private class data member.
 * PRE: Dead ends have been counted and stored in the instance for
 * the given input grid.
 * POST: The number of dead ends is returned.
 */
int cave::numDeadEnds() {
    return deadends;
}