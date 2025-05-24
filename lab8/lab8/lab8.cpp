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
        cout << "������� ��������������� �������: ";
        cin >> N;
    } while (N <= 0);

    do {
        cout << "������� ���������� ���������: ";
        cin >> M;
    } while (M <= 0);

    vector<string> name(M);
    vector<int> cost(M);
    vector<int> ves(M);

    for (int i = 0; i < M; i++) {
        cout << "������� �������� " << i + 1 << " ��������: ";
        cin >> name[i];

        do {
            cout << "������� ��������� " << i + 1 << " ��������: ";
            cin >> cost[i];
        } while (cost[i] <= 0);

        do {
            cout << "������� ��� " << i + 1 << " ��������: ";
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

    cout << "������������ ��������� ���������, ���������� � ������: " << A[M][N] << "\n"
        << "��������, ���������� � ������: \n";

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