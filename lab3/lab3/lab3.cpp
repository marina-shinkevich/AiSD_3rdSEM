#include <iostream>
#include <vector>
#include<Windows.h>
#include <climits>
#include "lab3.h"


using namespace std;

// Функция для нахождения вершины с минимальным расстоянием
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Алгоритм Дейкстры
void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false); 

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V); 

        sptSet[u] = true; 

      
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Массив букв 
    char vertices[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

    
    cout << "Вершина \t Расстояние от источника" << endl;
    for (int i = 0; i < V; i++) {
        cout << vertices[i] << " \t\t " << dist[i] << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Пример графа из изображения
    vector<vector<int>> graph = {
        {0, 7, 10, 0, 0, 0, 0, 0, 0}, // Вершина A
        {7, 0, 0, 0, 0, 9, 27, 0, 0}, 
        {10, 0, 0, 0, 31, 8, 0, 0, 0}, 
        {0, 0, 0, 0, 32, 0, 0, 17, 21}, 
        {0, 0, 31, 32, 0, 0, 0, 0, 0}, 
        {0, 9, 8, 0, 0, 0, 0, 11, 0},
        {0, 27, 0, 0, 0, 0, 0, 0, 15}, 
        {0, 0, 0, 17, 0, 11, 0, 0, 15}, 
        {0, 0, 0, 21, 0, 0, 15, 15, 0} 
    };

    int startVertex;
    cout << "Введите стартовую вершину (0-8, где 0=A, 1=B, ..., 8=I): ";
    cin >> startVertex;

    
    dijkstra(graph, startVertex, 9);

    return 0;
}