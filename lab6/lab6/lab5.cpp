
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int INF = 100000000000;

struct Edge
{
    int start;
    int end;
    int weight;
};


class Graph
{
private:
    int graphMat[8][8] = {
        {INF, 2, INF, 8, 2, INF, INF, INF},
        {2, INF, 3, 10, 5, INF, INF, INF},
        {INF, 3, INF, INF, 12, INF,INF, 7},
        {8, 10, INF, INF, 14, 3, 1, INF},
        {2, 5, 12, 14, INF, 11, 4, 8},
        {INF, INF, INF, 3, 11, INF, 6, INF},
        {INF, INF, INF, 1, 4, 6, INF, 9},
        {INF, INF, 7, INF, 8, INF, 9, INF}
    };

    vector <Edge> edgeList = {
    {1, 2, 2}, 
    {1, 4, 8}, 
    {7, 5, 4}, 
    {1, 5, 2}, 
    {2, 3, 3}, 
    {2, 5, 5}, 
    {2, 4, 10},
    {3, 5, 12},
    {3, 8, 7}, 
    {4, 5, 14}, 
    {4, 6, 3}, 
    {4, 7, 1}, 
    {5, 8, 8}, 
    {6, 7, 6}, 
    {7, 8, 9}, 
    {5, 6, 11}
    };

public:
    void PrimsAl(int startV);
    void KruskalsAl();
};


void Graph::PrimsAl(int startV) 
{
    int visited[8]; 
    for (int i = 0; i < 8; i++)
    {
        visited[i] = false;
    }

    visited[startV] = true; 
    int currentEdge = 0; 
    int x;
    int y;
    while (currentEdge < 7) 
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < 8; i++)
        {
            if (visited[i]) {
                for (int j = 0; j < 8; j++)
                { 
                    if (!visited[j])
                    {
                        if (min > graphMat[i][j])
                        { 
                            min = graphMat[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        
        cout << "V" << x + 1 << " - " << "V" << y + 1 << " : " << graphMat[x][y] << endl;
        visited[y] = true; 
        currentEdge++;
    }
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}
void Graph::KruskalsAl()
{
    int n = 8;
    int connectedVert[8]; 

    for (int i = 0; i < n; i++)
    {
        connectedVert[i] = i; 
    }

    

    std::sort(edgeList.begin(), edgeList.end(), compareEdges);

   
    for (Edge& a : edgeList)
    {
        if (connectedVert[a.start] != connectedVert[a.end])
        {
            cout << "V" << a.start << " - " << "V" << a.end << " : " << a.weight << endl;

            int oldVert = connectedVert[a.start], newVert = connectedVert[a.end];

            for (int i = 0; i < n; i++)
            {
                if (connectedVert[i] == oldVert)
                {
                    connectedVert[i] = newVert;
                }
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;

    int startV;

   
    
        cout << "Введите начальную вершину для Прима (от 1 до 8, 0 для выхода): ";
        cin >> startV;

        if (startV == 0) {
            cout << "Завершение программы." << endl;
           
        }

        startV -= 1;

        if (startV >= 0 && startV < 8) {
            cout << "PrimsAlgorithm" << endl;
            graph.PrimsAl(startV);

            cout << "KruskalsAlgoritm" << endl;
            graph.KruskalsAl();
        }
        else {
            cout << "Неверный ввод. Вершина должна быть от 1 до 8." << endl;
        }
    

    return 0;
}
