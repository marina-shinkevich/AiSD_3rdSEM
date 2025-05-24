#include <iostream>
#include <vector>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int countNumbers;

	while (true) {
		cout << "������� ����� ������������������: ";
		cin >> countNumbers;
		if (cin.get() != (int)'\n') {
			cout << "\n������ ������� �������, ���������� ��� ���!" << endl;
			cin.clear();
			continue;
		}
		else
			break;
	}
	vector <int> sequence(countNumbers);
	vector<int> maxLen(countNumbers);
	vector<int> next(countNumbers);

	cout << "������� ������:" << endl;
	while (true) {
		int i = 0;
		for (; i < countNumbers; i++) {
			cout << i + 1 << "-� �������: ";
			cin >> sequence[i];
			if (cin.get() != (int)'\n') {
				cout << "\n�������� ����, ������� �������!" << endl;
				cin.clear();
				break;
			}
			else
				continue;
		}
		if (i == countNumbers)
			break;
	}

	for (int i = countNumbers - 1; i >= 0; i--)
	{
		int maxNextLen = 0;
		int bestNext = -1;
		for (int j = i + 1; j < countNumbers; j++)
			if (sequence[j] > sequence[i])
				if (maxLen[j] > maxNextLen) {
					maxNextLen = maxLen[j];
					bestNext = j;
				}
		next[i] = bestNext;
		maxLen[i] = maxNextLen + 1;
	}
	int max = 0;
	int bestStart = -1;
	for (int i = 0; i < countNumbers; i++) {
		if (maxLen[i] > max) {
			max = maxLen[i];
			bestStart = i;
		}
	}

	cout << "������������ ����� ���������������������: " << max << endl;
	for (int i = bestStart; i != -1; i = next[i])
		cout << sequence[i] << " ";
	cout << endl;

	// ����� �������� maxLen � next
	cout << "\n������ maxLen: ";
	for (int i = 0; i < countNumbers; i++) {
		cout << maxLen[i] << " ";
	}
	cout << "\n������ next: ";
	for (int i = 0; i < countNumbers; i++) {
		cout << next[i] << " ";
	}
	cout << endl;
	return 0;
}