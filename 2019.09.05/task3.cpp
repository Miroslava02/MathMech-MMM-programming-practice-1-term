// Проверить число на простоту и вывести его делители 
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n, a = 0;
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) a++;
	}
	if (a == 0) cout << "prime" << endl;
	else cout << "composite" << endl;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cout << i << ' ';
	}
}