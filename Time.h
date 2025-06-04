#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <stdexcept>
using namespace std;
class Time {
private:
    short int hours;
    unsigned int minutes;

public:
    Time();  // Конструктор по умолчанию
    Time(short int h, unsigned int m);  // Конструктор с параметрами
    Time(const Time& other);  // Конструктор копирования

    // Геттеры
    short int getHours() const;
    unsigned int getMinutes() const;

    // Сеттеры
    void setHours(short int h);
    void setMinutes(unsigned int m);

    // Методы
    Time subtractMinutes(unsigned int m) const;

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Time& t);
};

#endif // TIME_H