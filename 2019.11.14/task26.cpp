// Реализовать алгоритм Нидлмана-Вунша (нахождение максимальной общей подпоследовательности)

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


void search(string a, string b, int** aa, int size_a, int size_b) {
	for (int i = 1; i < size_a; i++) {
		for (int j = 1; j < size_b; j++) {
			if (a[i - 1] == b[j - 1]) {
				aa[i][j] = aa[i - 1][j - 1] + 1;
			}
			else {
				if (aa[i - 1][j] > aa[i][j - 1]) {
					aa[i][j] = aa[i - 1][j];
				}
				else {
					aa[i][j] = aa[i][j - 1];
				}
			}
		}
	}
}
void LCS(string a, string b, int** aa, int size_a, int size_b) {
	char* lcs = new char[aa[size_a][size_b]];
	int k = 0;
	while (aa[size_a][size_b] != 0) {
		if (a[size_a - 1] == b[size_b - 1]) {
			lcs[k] = a[size_a - 1];
			size_a--;
			size_b--;
			k++;
		}
		else {
			if (aa[size_a - 1][size_b] > aa[size_a][size_b - 1]) {
				size_a--;
			}
			else {
				size_b--;
			}
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		cout << lcs[i];
	}
}
int main()
{
	string a, b;
	cin >> a >> b;
	int size_a = a.size() + 1;
	int size_b = b.size() + 1;
	int** aa = new int* [size_a];
	for (int i = 0; i < size_a; i++) {
		aa[i] = new int[size_b];
	}
	for (int i = 0; i < size_a; i++) {
		for (int j = 0; j < size_b; j++) {
			aa[i][j] = 0;
		}
	}
	search(a, b, aa, size_a, size_b);
	LCS(a, b, aa, size_a - 1, size_b - 1);
}