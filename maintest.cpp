/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Assignment 6: SortingAlgorithms

*/

#include <iostream>
#include <fstream>
#include <string>
#include "SortingAlgorithms.h"

using namespace std;

// takes in command line arguenrt and calls read file function
int main(int argc, char **argv){
    if(argc > 1){
      string inputFile = argv[1];
      SortingAlgorithms q;
      q.ReadFile(inputFile);
    }
}
