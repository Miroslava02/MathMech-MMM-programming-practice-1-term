/*Даны К упорядоченных массивов длины N содержащих целые числа.
написать программу. Проверить есть ли число входящее в каждый из массивов.
Выписать все такие числа. Программа должна работать за время не большее O(NK)
*/
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int** A = new int* [a];
	for (int i = 0; i < a; i++) {
		A[i] = new int[b];
	}
	int* B = new int[b];
	for (int i = 0; i < b; i++) {
		B[i] = -1;
	}
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) {
			cin >> A[i][j];
		}

	for (int i = 0, j = 0, g = 0; (i < b) && (j < b);) {
		if (A[0][i] == A[1][j]) {
			B[g] = A[1][j];
			g++;
			i++;
			j++;
		}
		if (A[0][i] < A[1][j]) {
			i++;
		}
		else {
			j++;
		}
	}
	bool f;
	for (int i = 2; i < a; i++) {
		for (int g = 0; g < b; g++) {
			f = false;

			for (int j = 0; j < b; j++)
			{
				if ((B[g] == A[i][j]) && (B[g] != -1)) {
					f = true;
				}
			}
			if (f != true) {
				B[g] = -1;
			}
		}
	}
	for (int i = 0; i < b; i++)
		if (B[i] != -1)cout << B[i] << " ";
}
