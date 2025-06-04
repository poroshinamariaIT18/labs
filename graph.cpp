#include "graph.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void Graph::buildIncidenceMatrix() {
    edgesCount = 0;

    // ������� ���������� �����
    for (int i = 0; i < verticesCount; ++i) {
        for (int j = i + 1; j < verticesCount; ++j) {
            if (adjMatrix[i][j] != 0) edgesCount++;
        }
    }

    // ���������� ������� �������������
    incMatrix.assign(verticesCount, vector<int>(edgesCount, 0));
    int currentEdge = 0;

    for (int i = 0; i < verticesCount; ++i) {
        for (int j = i + 1; j < verticesCount; ++j) {
            if (adjMatrix[i][j] != 0) {
                incMatrix[i][currentEdge] = 1;
                incMatrix[j][currentEdge] = 1;
                currentEdge++;
            }
        }
    }
}

bool Graph::validateAdjacencyMatrix() const {
    // �������� �������� �������
    if (adjMatrix.size() != verticesCount) return false;
    for (size_t i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[i].size() != verticesCount) return false;
    }

    // �������� �������������� � ���������� ������
    for (int i = 0; i < verticesCount; ++i) {
        if (adjMatrix[i][i] != 0) return false;
        for (int j = i + 1; j < verticesCount; ++j) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                return false;
            }
        }
    }

    // �������� ���������� ��������
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            if (val != 0 && val != 1) return false;
        }
    }

    return true;
}

bool Graph::readAdjacencyMatrix(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "������: �� ������� ������� ���� " << filename << endl;
        return false;
    }

    if (!(inputFile >> verticesCount)) {
        cerr << "������: �������� ������ ������� �������" << endl;
        return false;
    }

    adjMatrix.resize(verticesCount);
    for (int i = 0; i < verticesCount; ++i) {
        adjMatrix[i].resize(verticesCount);
        for (int j = 0; j < verticesCount; ++j) {
            if (!(inputFile >> adjMatrix[i][j])) {
                cerr << "������: �������� ������ ������ � �������" << endl;
                return false;
            }
        }
    }

    if (!validateAdjacencyMatrix()) {
        cerr << "������: ������������ ������� ���������" << endl;
        return false;
    }

    buildIncidenceMatrix();
    return true;
}

bool Graph::writeIncidenceMatrix(const string& filename) const {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "������: �� ������� ������� ���� " << filename << endl;
        return false;
    }

    outputFile << verticesCount << " " << edgesCount << endl;

    for (int i = 0; i < verticesCount; ++i) {
        for (int j = 0; j < edgesCount; ++j) {
            outputFile << incMatrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
    return true;
}