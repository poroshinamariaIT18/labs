#include "Time.h"
using namespace std;
// Конструктор по умолчанию
Time::Time() : hours(0), minutes(0) {}

// Конструктор с параметрами
Time::Time(short int h, unsigned int m) {
    if (h < 0 || h >= 24 || m >= 60) {
        throw invalid_argument("Некорректное время: часы должны быть от 0 до 23, минуты — от 0 до 59.");
    }
    hours = h;
    minutes = m;
}

// Конструктор копирования
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Геттеры
short int Time::getHours() const { return hours; }
unsigned int Time::getMinutes() const { return minutes; }

// Сеттеры
void Time::setHours(short int h) {
    if (h < 0 || h >= 24) {
        throw invalid_argument("Часы должны быть от 0 до 23.");
    }
    hours = h;
}

void Time::setMinutes(unsigned int m) {
    if (m >= 60) {
        throw invalid_argument("Минуты должны быть от 0 до 59.");
    }
    minutes = m;
}

// Вычитание минут
Time Time::subtractMinutes(unsigned int m) const {
    unsigned int totalMinutes = hours * 60 + minutes;
    unsigned int remainingMinutes = (totalMinutes + 1440 - m % 1440) % 1440;

    short int newHours = remainingMinutes / 60;
    unsigned int newMinutes = remainingMinutes % 60;

    return Time(newHours, newMinutes);
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return os;
}