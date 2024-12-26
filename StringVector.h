#ifndef SV_H
#define SV_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class sv
{
private:
   vector<string> words;
public:
   int LinearSearch(const string& w);
   void AddUnsorted(const string& w);
   void Print();
   int getCount() const;
   int BinarySearch(const string& word, int left, int right); 
   int AddSorted(const string& word);
   int AddSortedHelper(const string& word, int left, int right);





};
#endif