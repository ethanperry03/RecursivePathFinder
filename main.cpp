#include <iostream>
#include "cave.h"
using namespace std;

int main() {
    cave thecave;
    cout << "\nInitial grid: " << endl;
    thecave.displayCave();
    cout << "\nSearching for path(s) through cave..." << endl;
    thecave.searchPath();
    cout << "Path(s) found: " << endl;
    thecave.displayPath();
    cout << "\nDead ends: " << thecave.numDeadEnds() << endl;
    return 0;
}