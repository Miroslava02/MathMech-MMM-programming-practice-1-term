// Написать программу находящую среднее арифметическое факториалов последовательности чисел
#include <iostream>
using namespace std;
int main() {
	int n, a, i, i1, fact = 1, s = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		for (i1 = 1; i1 <= a; i1++) {
			fact = fact * i1;
		}
		s = s + fact;
		fact = 1;
	}
	if ((s % n) == 0) cout << s / n;
	else cout << s / n << ',' << s % n;
	return 0;
}