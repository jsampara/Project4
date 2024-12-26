#include "StringVector.h"

//Linear Search Method
int sv::LinearSearch(const string& word)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == word)
        {
            return i; // Word Found
        }
     
    }
    return -1; // Word not found
}
// Add word to the vector
void sv::AddUnsorted(const string& word)
{
    words.push_back(word);
}

// Print words and count
void sv::Print()
{
    for (const string& word : words)
    {
        cout << word << " ";
    }
    cout << "\nTotal words: " << words.size() << endl;
}
int sv::getCount() const 
{
    return words.size();  // Return the size of the vector
}
int sv::BinarySearch(const string& word, int left, int right) {
    if (left > right) {
        return -1; // Word not found
    }

    int mid = left + (right - left) / 2;

    if (words[mid] == word) {
        return mid; // Word found
    } 
    else if (words[mid] > word) {
        return BinarySearch(word, left, mid - 1); // Search left half
    } 
    else {
        return BinarySearch(word, mid + 1, right); // Search right half
    }
}

int sv::AddSorted(const string& word) 
{
    if (words.empty()) {
        words.push_back(word); // Add the first word
        return 0;
    }

    // Find position to insert or word if it already exists
    return AddSortedHelper(word, 0, words.size() - 1);
}

int sv::AddSortedHelper(const string& word, int left, int right) {
    if (left > right) {
        words.insert(words.begin() + left, word); // Insert at correct position
        return left;
    }

    int mid = left + (right - left) / 2;

    if(words[mid] == word) {
        return mid; // Word already exists
    } 
    else if (words[mid] > word) {
        return AddSortedHelper(word, left, mid - 1); // Search left half
    } 
    else {
        return AddSortedHelper(word, mid + 1, right); // Search right half
    }
}
