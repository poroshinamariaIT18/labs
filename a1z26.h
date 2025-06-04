#ifndef A1Z26_H
#define A1Z26_H

#include <string>

using namespace std;

// ������� ����������/������������
string encryptA1Z26(const string& text);
string decryptA1Z26(const string& cipher);

// ��������������� ������� ��������
bool isEnglishText(const string& str);
bool isValidCipher(const string& str);
bool containsRussianLetters(const string& str);

#endif // A1Z26_H