//Написать программу, находящую разложение натурального числа в сумму натуральных квадратов, с наименьшим числом слагаемых


#include <iostream>
#include <cmath>

using namespace std;

void search(int* a, int* x, int n) {
	x[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (x[i] < x[i - j * j] + 1) {
				x[i] = x[i];
			}
			else {
				x[i] = x[i - j * j] + 1;
			}
			if (x[i] == x[i - j * j] + 1) {
				a[i] = j;
			}
		}
	}
}


void decomposition(int* a, int n) {
	if (a[n] != -1) cout << a[n] << "^2";
	n = n - a[n] * a[n];
	if (n != 0) {
		cout << "+";
		decomposition(a, n);
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n + 1];
	int* x = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		a[i] = -1;
		x[i] = n;
	};
	search(a, x, n);
	decomposition(a, n);
}
