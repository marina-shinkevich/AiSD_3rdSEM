#include <iostream>
#include <Windows.h>

using namespace std;

void move(int disk, int from, int to) {
    cout << "Переместить диск " << disk << " с " << from << " на " << to << " стержень" << endl;
}

// Рекурсивная функция для решения задачи Ханойской башни
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


    cout << "Введите количество дисков (N): ";
    cin >> N;

    cout << "Введите номер стержня, на котором находятся диски (1, 2 или 3): ";
    cin >> from;

    cout << "Введите номер целевого стержня (1, 2 или 3): ";
    cin >> to;

    
    if (from < 1 || from > 3 || to < 1 || to > 3) {
        cout << "Номера стержней должны быть 1, 2 или 3!" << endl;
        return 1;
    }

    if (from == to) {
        cout << "Ошибка: номера стержней не могут быть одинаковыми!" << endl;
        return 1;
    }

    // вспомогательный стержень
    int aux = 6 - from - to;

    // Вызов функции для решения задачи
    hanoi(N, from, to, aux);

    return 0;
}
