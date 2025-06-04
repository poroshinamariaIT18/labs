#include "hamming.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

// ������� ��� ����������� ������� ����������� ����� � ���� ��������
vector<int> getParityBitsPositions(int dataSize) {
    vector<int> positions; // ������ ��� �������� ������� ����������� �����
    int r = 0; 

    // ��������� ����������� ���������� ����������� �����
    
    while (pow(2, r) < dataSize + r + 1) {
        r++;
    }

    // ��������� ������ ��������� ����������� ����� (������� ������)
    for (int i = 0; i < r; i++) {
        positions.push_back(pow(2, i)); 
    }

    return positions;
}

// ������� ��� �������� ���� �������� �� �������� ������
vector<int> createHammingCode(const string& data) {
    int m = data.size(); // ������ �������� ������
    vector<int> parityPositions = getParityBitsPositions(m); 
    int n = m + parityPositions.size(); 

    // ������� ������ ��� ���� �������� � ����������� � 1
    vector<int> hammingCode(n + 1);

    
    for (int pos : parityPositions) {
        hammingCode[pos] = -1;
    }

    // ��������� ���� ������ � ��������������� �������
    int dataIndex = 0; 
    for (int i = 1; i <= n; i++) {
        // ���� ������� ������� �� ��� ������������ ����
        if (hammingCode[i] != -1) {
            hammingCode[i] = data[dataIndex++] - '0'; // ����������� ������ '0'/'1' � �����
        }
    }

    // ��������� �������� ����������� �����
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

// ������� ��� ����������� � ����������� ������ � ���� ��������
void detectAndCorrectError(vector<int>& hammingCode) {
    // ��������� ������� ����������� ����� ��� ��������
   
    vector<int> parityPositions = getParityBitsPositions(
        hammingCode.size() - 1 - getParityBitsPositions(hammingCode.size() - 1).size());

    int errorPos = 0; // ������� ������ (0 - ��� ������)

    // ��������� ������ ����������� ���
    for (int pos : parityPositions) {
        int xorResult = 0;
        // ��������� XOR ��� ���� �����, ����������� ������ ����������� �����
        for (int i = 1; i < hammingCode.size(); i++) {
            if ((i & pos) == pos) {
                xorResult ^= hammingCode[i];
            }
        }
        // ���� XOR �� ����� 0, ������ ���� ������
        if (xorResult != 0) {
            errorPos += pos; // ��������� ������� ��� ����������� ����� ������
        }
    }

    
    if (errorPos != 0 && errorPos < hammingCode.size()) {
        
        cout << "������ ���������� �� �������: " << errorPos << endl;
        hammingCode[errorPos] ^= 1; // ����������� ��������� ���
        cout << "������ ����������." << endl;
    }
    else if (errorPos != 0) {
        
        cout << "���������� ������, �� ������� �� ��������� ����." << endl;
    }
    else {
       
        cout << "������ �� ����������." << endl;
    }
}

// ������� ��� ������ ���� ��������
void printHammingCode(const vector<int>& hammingCode) {
    cout << "��� ��������: ";
    
    for (size_t i = 1; i < hammingCode.size(); i++) {
        cout << hammingCode[i];
    }
    cout << endl;
}