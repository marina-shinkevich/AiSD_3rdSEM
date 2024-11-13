#include <iostream>
#include <vector>

#include<Windows.h>
using namespace std;

const int INF = 100000;


void printMatrix(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Алгоритм Флойда-Уоршелла
void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph; 
    vector<vector<int>> next(n, vector<int>(n, 0));  

  
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j+1;
            }
        }
    }

    
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

   
    cout << "Матрица кратчайших путей:\n";
    printMatrix(dist, n);

    cout << "\nМатрица последовательности вершин:\n";
    printMatrix(next, n);
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 6;  
    vector<vector<int>> graph = {
        {0, 28, 21, 59, 12, 27},
        {7, 0, 24, INF, 21, 9},
        {9, 32, 0, 13, 11, INF},
        {8, INF, 5, 0, 16, INF},
        {14, 13, 15, 10, 0, 22},
        {15, 18, INF, INF, 6, 0}
    };

    floydWarshall(graph, n);
    return 0;
}
