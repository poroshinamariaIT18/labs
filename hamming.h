#ifndef HAMMING_H
#define HAMMING_H

#include <vector>
#include <string>
using namespace std;
vector<int> getParityBitsPositions(int dataSize);
vector<int> createHammingCode(const string& data);
void detectAndCorrectError(vector<int>& hammingCode);
void printHammingCode(const vector<int>& hammingCode);

#endif // HAMMING_H