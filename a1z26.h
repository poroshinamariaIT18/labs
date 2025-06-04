#ifndef A1Z26_H
#define A1Z26_H

#include <string>

using namespace std;

// Функции шифрования/дешифрования
string encryptA1Z26(const string& text);
string decryptA1Z26(const string& cipher);

// Вспомогательные функции проверки
bool isEnglishText(const string& str);
bool isValidCipher(const string& str);
bool containsRussianLetters(const string& str);

#endif // A1Z26_H