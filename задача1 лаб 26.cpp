#include "graph.h"
#include <iostream>
using namespace std;
int main() {
    Graph graph;

    if (!graph.readAdjacencyMatrix("FileName1.txt")) {
        cerr << "Программа завершена с ошибками" << endl;
        return 1;
    }

    if (!graph.writeIncidenceMatrix("FileName2.txt")) {
        cerr << "Ошибка при записи результата" << endl;
        return 1;
    }

    cout << "Конвертация завершена успешно!" << endl;
    cout << "Статистика:\n"
        << "Вершин: " << graph.getVerticesCount() << "\n"
        << "Рёбер: " << graph.getEdgesCount() << endl;
    return 0;
}