// Реализовать функцию Аккермана
#include <iostream>
using namespace std;
int f(int m, int n) {
	if (m == 0) return n + 1;
	if (m > 0 && n == 0) return f(m - 1, 1);
	if (m > 0 && n > 0) {
		int res = f(m, n - 1);
		return f(m - 1, res);
	}
}
int main() {
	int m, n, z;
	cin >> m >> n;
	z = f(m, n);
	cout << z;
}