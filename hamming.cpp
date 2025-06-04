#include "hamming.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

// Функция для определения позиций контрольных битов в коде Хемминга
vector<int> getParityBitsPositions(int dataSize) {
    vector<int> positions; // Вектор для хранения позиций контрольных битов
    int r = 0; 

    // Вычисляем необходимое количество контрольных битов
    
    while (pow(2, r) < dataSize + r + 1) {
        r++;
    }

    // Заполняем вектор позициями контрольных битов (степени двойки)
    for (int i = 0; i < r; i++) {
        positions.push_back(pow(2, i)); 
    }

    return positions;
}

// Функция для создания кода Хемминга из исходных данных
vector<int> createHammingCode(const string& data) {
    int m = data.size(); // Размер исходных данных
    vector<int> parityPositions = getParityBitsPositions(m); 
    int n = m + parityPositions.size(); 

    // Создаем вектор для кода Хемминга с индексацией с 1
    vector<int> hammingCode(n + 1);

    
    for (int pos : parityPositions) {
        hammingCode[pos] = -1;
    }

    // Заполняем биты данных в соответствующие позиции
    int dataIndex = 0; 
    for (int i = 1; i <= n; i++) {
        // Если текущая позиция не для контрольного бита
        if (hammingCode[i] != -1) {
            hammingCode[i] = data[dataIndex++] - '0'; // Преобразуем символ '0'/'1' в число
        }
    }

    // Вычисляем значения контрольных битов
    for (int pos : parityPositions) {
        int xorResult = 0; 

        
        for (int i = 1; i <= n; i++) {
         
            if (i != pos && (i & pos) == pos) {
                xorResult ^= hammingCode[i]; 
            }
        }
        hammingCode[pos] = xorResult;
    }

    return hammingCode;
}

// Функция для обнаружения и исправления ошибок в коде Хемминга
void detectAndCorrectError(vector<int>& hammingCode) {
    // Вычисляем позиции контрольных битов для проверки
   
    vector<int> parityPositions = getParityBitsPositions(
        hammingCode.size() - 1 - getParityBitsPositions(hammingCode.size() - 1).size());

    int errorPos = 0; // Позиция ошибки (0 - нет ошибки)

    // Проверяем каждый контрольный бит
    for (int pos : parityPositions) {
        int xorResult = 0;
        // Вычисляем XOR для всех битов, покрываемых данным контрольным битом
        for (int i = 1; i < hammingCode.size(); i++) {
            if ((i & pos) == pos) {
                xorResult ^= hammingCode[i];
            }
        }
        // Если XOR не равен 0, значит есть ошибка
        if (xorResult != 0) {
            errorPos += pos; // Суммируем позиции для определения места ошибки
        }
    }

    
    if (errorPos != 0 && errorPos < hammingCode.size()) {
        
        cout << "Ошибка обнаружена на позиции: " << errorPos << endl;
        hammingCode[errorPos] ^= 1; // Инвертируем ошибочный бит
        cout << "Ошибка исправлена." << endl;
    }
    else if (errorPos != 0) {
        
        cout << "Обнаружена ошибка, но позиция за пределами кода." << endl;
    }
    else {
       
        cout << "Ошибок не обнаружено." << endl;
    }
}

// Функция для вывода кода Хемминга
void printHammingCode(const vector<int>& hammingCode) {
    cout << "Код Хемминга: ";
    
    for (size_t i = 1; i < hammingCode.size(); i++) {
        cout << hammingCode[i];
    }
    cout << endl;
}