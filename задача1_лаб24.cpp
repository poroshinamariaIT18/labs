#include "hamming.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    string data;
    cout << "Введите исходное сообщение (бинарная строка): ";
    cin >> data;

    // Проверка на корректность ввода
    for (char c : data) {
        if (c != '0' && c != '1') {
            cerr << "Ошибка: в сообщении должны быть только '0' и '1'" << endl;
            return 1;
        }
    }

    // Создаем код Хемминга
    vector<int> hammingCode = createHammingCode(data);
    printHammingCode(hammingCode);

    // Ввод позиции для ошибки
    int errorBit;
    cout << "Введите позицию бита для внесения ошибки (1-" << hammingCode.size() - 1 << "), или 0 чтобы пропустить: ";
    cin >> errorBit;

    // Проверка ввода
    while (cin.fail() || errorBit < 0 || errorBit >= hammingCode.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод. Пожалуйста, введите число от 0 до " << hammingCode.size() - 1 << ": ";
        cin >> errorBit;
    }

    if (errorBit > 0) {
        // Вносим ошибку
        hammingCode[errorBit] ^= 1;
        cout << "Введена ошибка в " << errorBit << "-й бит." << endl;
        printHammingCode(hammingCode);

        // Обнаруживаем и исправляем ошибку
        detectAndCorrectError(hammingCode);
        printHammingCode(hammingCode);
    }

    return 0;
}