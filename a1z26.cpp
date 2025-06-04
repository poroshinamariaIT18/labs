#include "a1z26.h"
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// Проверяет, содержание  русских букв
bool containsRussianLetters(const string& str) {
    for (char c : str) {
        if ((c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё') {
            return true;  
        }
    }
    return false;  
}

// Проверяет, что строка содержит только английские буквы 
bool isEnglishText(const string& str) {
    if (containsRussianLetters(str)) {
        return false;
    }
    return all_of(str.begin(), str.end(), [](char c) {
        return isalpha(c) || isspace(c);
        });
}

// Проверяет корректность зашифрованной строки
bool isValidCipher(const string& str) {
    if (str.empty()) return false;  
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (!(isdigit(c) || (c == '-' && i > 0 && i < str.size() - 1 && str[i - 1] != '-'))) {
            return false;
        }
    }
    return true;
}

// Шифрует текст по алгоритму A1Z26
string encryptA1Z26(const string& text) {
    string result;  
    for (char c : text) {
        if (isalpha(c)) {  
            char upper = toupper(c);
            // Вычисляем номер буквы в алфавите (A=1, B=2, ...)
            int num = upper - 'A' + 1;

            // Добавляем разделитель, если это не первый элемент
            if (!result.empty()) {
                result += "-";
            }
           
            result += to_string(num);
        }
        else if (isspace(c)) {  // Если символ - пробел
            // Заменяем пробел на / (чтобы сохранить разделение слов)
            if (!result.empty() && result.back() != '/') {
                result += "/";
            }
        }
    }
    
    if (!result.empty() && result.back() == '/') {
        result.pop_back();
    }
    return result;
}

// Дешифрует строку из чисел обратно в текст
string decryptA1Z26(const string& cipher) {
    string result;  
    istringstream iss(cipher);  
    string token;  

    // Читаем строку по токенам, разделенным дефисами
    while (getline(iss, token, '-')) {
        if (token.find('/') != string::npos) {
            istringstream spaceIss(token);  
            string spaceToken; 
            while (getline(spaceIss, spaceToken, '/')) {
                if (spaceToken.empty()) {
                    result += " ";  
                    continue;
                }
                try {
                    // Преобразуем строку в число
                    int num = stoi(spaceToken);
                    // Если число в допустимом диапазоне
                    if (num >= 1 && num <= 26) {
                        // Преобразуем число обратно в букву
                        char c = 'A' + num - 1;
                        result += c;
                    }
                }
                catch (...) {  
                    continue;
                }
                result += " ";  
            }
            // Удаляем лишний пробел в конце, если есть
            if (!result.empty() && result.back() == ' ') {
                result.pop_back();
            }
        }
        else {  // Если токен не содержит пробелов
            try {
                // Преобразуем строку в число
                int num = stoi(token);
                // Если число в допустимом диапазоне
                if (num >= 1 && num <= 26) {
                    // Преобразуем число обратно в букву
                    char c = 'A' + num - 1;
                    result += c;
                }
            }
            catch (...) {  
                continue;
            }
        }
    }
    return result;
}