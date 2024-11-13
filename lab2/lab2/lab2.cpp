#include <iostream>
#include <queue>
#include<Windows.h>
#include <stack>
#include <limits> 


using namespace std;

const int N = 10;
const int E = 11;


int edgeList[E][2] = { {1, 2}, {1, 5}, {2, 7}, {2, 8}, {5, 6}, {7, 8}, {8, 3}, {6, 4}, {6, 9}, {4, 9}, {9, 10} };

// матрица смежности
int adjMatrix[N][N] = { 0 };

// список смежности
int adjList[N][N] = { 0 };
int adjCount[N] = { 0 };

void createAdjMatrix() {
    for (int i = 0; i < E; i++) {
        int u = edgeList[i][0] - 1;
        int v = edgeList[i][1] - 1;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}

void createAdjList() {
    for (int i = 0; i < E; i++) {
        int u = edgeList[i][0] - 1;
        int v = edgeList[i][1] - 1;
        adjList[u][adjCount[u]++] = v;
        adjList[v][adjCount[v]++] = u;
    }
}

void printEdgeList() {
    cout << "Список рёбер:" << endl;
    for (int i = 0; i < E; i++) {
        cout << edgeList[i][0] << " - " << edgeList[i][1] << endl;
    }
    cout << endl;
}

void printAdjMatrix() {
    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printAdjList() {
    cout << "Список смежности:" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < adjCount[i]; j++) {
            cout << adjList[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// BFS
void bfs(int start) {
    bool visited[N] = { false };
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS : ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v + 1 << " ";

        for (int i = 0; i < adjCount[v]; i++) {
            int u = adjList[v][i];
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

// DFS
void dfs(int start) {
    bool visited[N] = { false };
    stack<int> s;
    s.push(start);

    cout << "DFS : ";
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            visited[v] = true;
            cout << v + 1 << " ";

            for (int i = adjCount[v] - 1; i >= 0; i--) {
                int u = adjList[v][i];
                if (!visited[u]) {
                    s.push(u);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    createAdjMatrix();
    createAdjList();

    while (true) {
        int choice;
        cout << "Введите начальную вершину (от 1 до " << N << ", введите 0 для выхода): ";

        // Проверка корректного ввода
        while (!(cin >> choice) || choice < 0 || choice > N) {
            cout << "Ошибка ввода! Введите число от 0 до " << N << ": ";
            cin.clear(); 
            
        }

        // Проверка на выход
        if (choice == 0) {
            cout << "Программа завершена." << endl;
            break;
        }

        int startVertex = choice - 1;

        printEdgeList();
        printAdjMatrix();
        printAdjList();
        bfs(startVertex);
        dfs(startVertex);
    }

    return 0;
}
