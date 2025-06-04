#include "Time.h"
using namespace std;
// ����������� �� ���������
Time::Time() : hours(0), minutes(0) {}

// ����������� � �����������
Time::Time(short int h, unsigned int m) {
    if (h < 0 || h >= 24 || m >= 60) {
        throw invalid_argument("������������ �����: ���� ������ ���� �� 0 �� 23, ������ � �� 0 �� 59.");
    }
    hours = h;
    minutes = m;
}

// ����������� �����������
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// �������
short int Time::getHours() const { return hours; }
unsigned int Time::getMinutes() const { return minutes; }

// �������
void Time::setHours(short int h) {
    if (h < 0 || h >= 24) {
        throw invalid_argument("���� ������ ���� �� 0 �� 23.");
    }
    hours = h;
}

void Time::setMinutes(unsigned int m) {
    if (m >= 60) {
        throw invalid_argument("������ ������ ���� �� 0 �� 59.");
    }
    minutes = m;
}

// ��������� �����
Time Time::subtractMinutes(unsigned int m) const {
    unsigned int totalMinutes = hours * 60 + minutes;
    unsigned int remainingMinutes = (totalMinutes + 1440 - m % 1440) % 1440;

    short int newHours = remainingMinutes / 60;
    unsigned int newMinutes = remainingMinutes % 60;

    return Time(newHours, newMinutes);
}

// ���������� ��������� ������
ostream& operator<<(ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return os;
}