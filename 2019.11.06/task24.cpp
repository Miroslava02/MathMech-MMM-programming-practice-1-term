// Написать программу, находящую разложение натурального числа в сумму натуральных квадратов, с наименьшим числом слагаемых


#include <iostream>
#include <cmath>

using namespace std;

bool rec(int n) {
	if (n == 0) {
		return true;
	}
	cout << (int) sqrt(n) << "^2";
	if (n - (int)sqrt(n) * (int)sqrt(n) != 0) {
		cout << " + ";
	}
	rec(n - (int)sqrt(n) * (int)sqrt(n));
	return true;
}
int main() {
	int a;
	cin >> a;
	cout << a << " = ";
	rec(a);
	cout << endl;
}