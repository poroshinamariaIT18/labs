#include "a1z26.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "Шифратор/дешифратор A1Z26\n";
    cout << "1. Зашифровать текст\n";
    cout << "2. Расшифровать текст\n";
    cout << "Выберите действие (1 или 2): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный ввод. Пожалуйста, введите 1 или 2: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 1) {
        string text;
        while (true) {
            cout << "Введите текст для шифрования (английские буквы): ";
            getline(cin, text);

            if (containsRussianLetters(text)) {
                cout << "Ошибка: русские буквы недопустимы!\n";
                continue;
            }

            if (isEnglishText(text)) {
                break;
            }
            cout << "Ошибка: разрешены только английские буквы и пробелы!\n";
        }

        string cipher = encryptA1Z26(text);
        cout << "Зашифрованный текст: " << cipher << "\n";
    }
    else {
        string cipher;
        while (true) {
            cout << "Введите текст для дешифрования (числа 1-26, разделённые дефисами): ";
            getline(cin, cipher);

            if (isValidCipher(cipher)) {
                break;
            }
            cout << "Ошибка: разрешены только числа 1-26, разделённые дефисами!\n";
        }

        string text = decryptA1Z26(cipher);
        cout << "Расшифрованный текст: " << text << "\n";
    }

    return 0;
}