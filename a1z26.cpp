#include "a1z26.h"
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

// ���������, ����������  ������� ����
bool containsRussianLetters(const string& str) {
    for (char c : str) {
        if ((c >= '�' && c <= '�') || c == '�' || c == '�') {
            return true;  
        }
    }
    return false;  
}

// ���������, ��� ������ �������� ������ ���������� ����� 
bool isEnglishText(const string& str) {
    if (containsRussianLetters(str)) {
        return false;
    }
    return all_of(str.begin(), str.end(), [](char c) {
        return isalpha(c) || isspace(c);
        });
}

// ��������� ������������ ������������� ������
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

// ������� ����� �� ��������� A1Z26
string encryptA1Z26(const string& text) {
    string result;  
    for (char c : text) {
        if (isalpha(c)) {  
            char upper = toupper(c);
            // ��������� ����� ����� � �������� (A=1, B=2, ...)
            int num = upper - 'A' + 1;

            // ��������� �����������, ���� ��� �� ������ �������
            if (!result.empty()) {
                result += "-";
            }
           
            result += to_string(num);
        }
        else if (isspace(c)) {  // ���� ������ - ������
            // �������� ������ �� / (����� ��������� ���������� ����)
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

// ��������� ������ �� ����� ������� � �����
string decryptA1Z26(const string& cipher) {
    string result;  
    istringstream iss(cipher);  
    string token;  

    // ������ ������ �� �������, ����������� ��������
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
                    // ����������� ������ � �����
                    int num = stoi(spaceToken);
                    // ���� ����� � ���������� ���������
                    if (num >= 1 && num <= 26) {
                        // ����������� ����� ������� � �����
                        char c = 'A' + num - 1;
                        result += c;
                    }
                }
                catch (...) {  
                    continue;
                }
                result += " ";  
            }
            // ������� ������ ������ � �����, ���� ����
            if (!result.empty() && result.back() == ' ') {
                result.pop_back();
            }
        }
        else {  // ���� ����� �� �������� ��������
            try {
                // ����������� ������ � �����
                int num = stoi(token);
                // ���� ����� � ���������� ���������
                if (num >= 1 && num <= 26) {
                    // ����������� ����� ������� � �����
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