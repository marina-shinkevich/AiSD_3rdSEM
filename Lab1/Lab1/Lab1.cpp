#include <iostream>
#include <Windows.h>

using namespace std;

void move(int disk, int from, int to) {
    cout << "����������� ���� " << disk << " � " << from << " �� " << to << " ��������" << endl;
}

// ����������� ������� ��� ������� ������ ��������� �����
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to);
    move(n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int N;
    int from, to;


    cout << "������� ���������� ������ (N): ";
    cin >> N;

    cout << "������� ����� �������, �� ������� ��������� ����� (1, 2 ��� 3): ";
    cin >> from;

    cout << "������� ����� �������� ������� (1, 2 ��� 3): ";
    cin >> to;

    
    if (from < 1 || from > 3 || to < 1 || to > 3) {
        cout << "������ �������� ������ ���� 1, 2 ��� 3!" << endl;
        return 1;
    }

    if (from == to) {
        cout << "������: ������ �������� �� ����� ���� �����������!" << endl;
        return 1;
    }

    // ��������������� ��������
    int aux = 6 - from - to;

    // ����� ������� ��� ������� ������
    hanoi(N, from, to, aux);

    return 0;
}
