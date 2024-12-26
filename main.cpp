/* 
Joel Sampara
011028144
Project 4
*/

#include <iostream>
#include <fstream>
#include <string>
#include "StringVector.h"
#include <ctime>
using namespace std;



void analyzeBook(const string &fname, sv &v) {
    ifstream file(fname);
    string word;
    while (file >> word) {
        if (v.BinarySearch(word, 0, v.getCount() - 1) == -1) {
            v.AddSorted(word); // Add the word in sorted order if it's not in the vector
        }
    }
}


int main() 
{
   
    string files[]  = {"books:CallWild.txt", "books:AnneGables.txt", "books:WarPeace.txt"};

    // Process each file
    for (const string &file : files) {

        sv stringvec;
        clock_t startTime, endTime;
        double timeTaken;

        // Start timing
        startTime = clock();
        analyzeBook(file, stringvec);  // Process the file
        endTime = clock();

        // Calculate the time taken to process the file
        timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;

        // Output the results
        cout << "Number of unique words in " << file << ": " << stringvec.getCount() << endl;
        cout << "Time taken to process the file: " << timeTaken << " seconds\n\n";
    }
    

    return 0;
}
