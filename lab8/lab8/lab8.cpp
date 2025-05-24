#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N, M;

    do {
        cout << "Введите вместительность рюкзака: ";
        cin >> N;
    } while (N <= 0);

    do {
        cout << "Введите количество предметов: ";
        cin >> M;
    } while (M <= 0);

    vector<string> name(M);
    vector<int> cost(M);
    vector<int> ves(M);

    for (int i = 0; i < M; i++) {
        cout << "Введите название " << i + 1 << " предмета: ";
        cin >> name[i];

        do {
            cout << "Введите стоимость " << i + 1 << " предмета: ";
            cin >> cost[i];
        } while (cost[i] <= 0);

        do {
            cout << "Введите вес " << i + 1 << " предмета: ";
            cin >> ves[i];
        } while (ves[i] <= 0);
    }

    vector<vector<int>> A(M + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (ves[i - 1] <= j) {
                A[i][j] = max(A[i - 1][j], A[i - 1][j - ves[i - 1]] + cost[i - 1]);
            }
            else {
                A[i][j] = A[i - 1][j];
            }
        }
    }

    cout << "Максимальная стоимость предметов, положенных в рюкзак: " << A[M][N] << "\n"
        << "Предметы, положенные в рюкзак: \n";

    int i = M, j = N;
    while (i > 0 && j > 0) {
        if (A[i][j] != A[i - 1][j]) {
            cout << name[i - 1] << "\n";
            j -= ves[i - 1];
        }
        i--;
    }

    return 0;
}