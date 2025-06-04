#include "Time.h"
#include <iostream>
#include <limits>
using namespace std;
int main() {
    // Создаём три объекта времени
    Time t1; // по умолчанию 00:00
    Time t2(0, 0); // будет введено пользователем
    Time t3(t1); // копия t1

    // Ввод времени t2 с клавиатуры
    int hours, minutes;
    while (true) {
        cout << "Введите время t2 (часы и минуты через пробел, часы 0-23, минуты 0-59): ";
        if (cin >> hours >> minutes) {
            try {
                t2 = Time(hours, minutes);
                break;
            }
            catch (const invalid_argument& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, введите числа." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Вывод всех времён
    cout << "\nТекущие времена:" << endl;
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    // Ввод минут для вычитания
    unsigned int minutes_to_subtract;
    while (true) {
        cout << "\nВведите количество минут для вычитания: ";
        if (cin >> minutes_to_subtract) {
            break;
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, введите целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Выбор времени для вычитания
    int choice;
    while (true) {
        cout << "\nВыберите время, из которого вычесть минуты (1 - t1, 2 - t2, 3 - t3): ";
        if (cin >> choice && choice >= 1 && choice <= 3) {
            break;
        }
        else {
            cout << "Некорректный выбор. Пожалуйста, введите 1, 2 или 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Выполнение вычитания и вывод результата
    Time result;
    switch (choice) {
    case 1:
        result = t1.subtractMinutes(minutes_to_subtract);
        cout << "Результат (t1 - " << minutes_to_subtract << " мин): " << result <<endl;
        break;
    case 2:
        result = t2.subtractMinutes(minutes_to_subtract);
        cout << "Результат (t2 - " << minutes_to_subtract << " мин): " << result << endl;
        break;
    case 3:
        result = t3.subtractMinutes(minutes_to_subtract);
        cout << "Результат (t3 - " << minutes_to_subtract << " мин): " << result << endl;
        break;
    }

    return 0;
}