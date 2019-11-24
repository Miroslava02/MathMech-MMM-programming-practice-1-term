// Реализовать решето Эратосфена

#include <iostream>
using namespace std;

void r(bool E[], int n) {
	int a;
	for (a = 2; a < n; a++) E[a] = 1;
	a = 2;
	int i;
	while (a * a < n) {
		i = a * a;
		if (E[a])
			while ( i < n) {
				E[i] = 0;
				i = i + a;
			}
		a++;
	}
	for (a = 2; a < n; a++) {
		if (E[a] == 1) {
			cout << a << " ";
		}
	}
}

int main()
{
	int n;
	cin >> n;
	bool* E = new bool[n];
	r(E, n);
}