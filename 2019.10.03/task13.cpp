/*Написать функции проверяющие является ли число:
Числом Мерсена
Числом Ферма
Числом Вильсона
Числом Вагстафа
Числом Вивериха
Числом Софи Жермен
Числом Хиггса
*/
#include <iostream>
#include <cmath>
using namespace std;

bool p(int N) { //простота
	for (int i = 2; i <= sqrt(N); i++) if (N % i == 0) {
		return 0;
	}
	return 1;
}
void Mersen(int N) { //Число Мерсена
	if (N != 2) {
		N = N + 1;
		while (N % 2 == 0) N = N / 2;
		if (N == 1) {
			cout << "Mersen";
		}
		else {
			cout << "=! Mersen";
		}
		cout << endl;
	}
}
void Ferma(int N) { //Число Ферма
	N = N - 1;
	int k = 0;
	while (N % 2 == 0) {
		N = N / 2;
		k = k + 1;
	}
	if (N == 1)
		while (k % 2 == 0) {
			k = k / 2;
		}
	if (N == 1 && k == 1) {
		cout << "Ferma";
	}
	else {
		cout << "!= Ferma";
	}
	cout << endl;
}
void Wilson(int N) { //Число Вильсона

	if (p(N)) {
		long int p = 1;
		for (int i = 1; i <= N - 1; i++) {
			p = (p * i) % (N * N);
		}
		if ((p + 1) % (N * N) == 0) {
			cout << "Wilson";
		}
		else {cout << "!= Wilson";
		}
	}
	else cout << "not wilson";
	cout << endl;
}
void Wagstaff(int N) { //Число Вагстафа

	if (p(N)) {
		int k = 4; int s = 2;
		for (int i = 2; k + 1 < 3 * N; i++) {
			s++;
			k *= 2;
		}

		if ((p(s)) && (3 * N == (k + 1))) {
			cout << "Wagstaff";
		}
		else {
			cout << "=! Wagstaff";
		}
	}
	else {
		cout << "!= Wagstaff";
	}
	cout << endl;

}
void Wieferich(int N) { //Числом Вивериха
	if (p(N)) {
		long int k = 1;
		for (int i = 1; i <= N - 1; i++) {
			k = (k * 2) % (N * N);
		}
		if ((k - 1) % (N * N) == 0) {
			cout << "Wieferich";
		}
		else {
			cout << "!= Wieferich";
		}
	}
	else {
		cout << "Wieferich";
	}
	cout << endl;
}

void SophieGermain(int N) { //Число Софи Жермен
	if ((p(N)) && (p(2 * N + 1))) {
		cout << "Sophie Germain";
	}
	else {
		cout << "!= Sophie Germain";
	}
	cout << endl;
}


int main()
{
	int N;
	cin >> N;
	if (N == 1) {
		cout << "!= Mersen, " << "!= Ferma, " << "Wilson, " << "!= Wagstaff, " << "Wieferich, " << "Sophie Germain";
	}
	if (N == 2) {
		cout << "=! Mersen" << endl << "!= Ferma" << endl << "!= Wilson" << endl << "!= Wagstaff" << endl << "!= Wieferich" << endl << "Sophie Germain";
	}
	else {
		Mersen(N);
		Ferma(N);
		Wilson(N);
		Wagstaff(N);
		Wieferich(N);
		SophieGermain(N);
	}
}
