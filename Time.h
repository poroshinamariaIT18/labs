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
    Time();  // ����������� �� ���������
    Time(short int h, unsigned int m);  // ����������� � �����������
    Time(const Time& other);  // ����������� �����������

    // �������
    short int getHours() const;
    unsigned int getMinutes() const;

    // �������
    void setHours(short int h);
    void setMinutes(unsigned int m);

    // ������
    Time subtractMinutes(unsigned int m) const;

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const Time& t);
};

#endif // TIME_H