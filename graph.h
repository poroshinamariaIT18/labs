#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
using namespace std;
class Graph {
private:
    vector<vector<int>> adjMatrix;
    vector<vector<int>> incMatrix;
    int verticesCount = 0;
    int edgesCount = 0;

    void buildIncidenceMatrix();
    bool validateAdjacencyMatrix() const; // Объявление функции проверки

public:
    bool readAdjacencyMatrix(const string& filename);
    bool writeIncidenceMatrix(const string& filename) const;

    int getVerticesCount() const { return verticesCount; }
    int getEdgesCount() const { return edgesCount; }
    const vector<vector<int>>& getIncidenceMatrix() const { return incMatrix; }
};

#endif // GRAPH_H