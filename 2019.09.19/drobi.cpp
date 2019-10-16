// Реализовать структуру данных (с примером использования) для хранения рациональных чисел в виде
// несократимых дробей. Перегрузить арифметику, сравнения, сделать конструкторы и оператор присвоения
// от рациональных чисел, пар целых и просто целых чисел.

#include <iostream>
using namespace std;

struct R {
	int n, m;
	//поиск наибольшего общего делителя
	int gcd(int n, int m) {
		if (m == 0) return n;
		return gcd(m, n % m);
	}
	//сокращение дроби на НОД
	R(int x = 0, int y = 1) {
		n = x / gcd(x, y);
		m = y / gcd(x, y);
	}
	//оператор умножить-равно
	R& operator *=(R z) {
		n *= z.n;
		m *= z.m;
		int g = gcd(n, m);
		m = m / g;
		n = n / g;
		return *this;
	}
	//домножение на натуральное число
	R& operator *= (int l) {
		n *= l;
		m *= l;
		return *this;
	}
	
};

//проверка на равенство
bool operator == (R r1, R r2) {
	return (r1.n == r2.n && r1.m == r2.m);

}
//проверка на неравенство
bool operator != (R r1, R r2) {
	return !(r1 == r2);
}

int gcd(int n, int m) {
	if (m == 0) return n;
	return gcd(m, n % m);
}
//приведение к общему знаменателю (возвращает знаменатель)
int znam(R r1, R r2) {
	if (r1.m == r2.m) return r1.m; //если знаменатели совпадают
	else {
		if (gcd(r1.m, r2.m) == 1) { //если знаменатели взаимно простые
			int k;
			k = r1.m * r2.m;
			return k;
		}
		else {
			int max_znam, i = 2;
			if (r1.m > r2.m) max_znam = r1.m;
			while (max_znam % r2.m != 0) {
				max_znam = max_znam * i;
				i++;
			}
			if (r1.m < r2.m) max_znam = r2.m;
			while (max_znam % r1.m != 0) {
				max_znam = max_znam * i;
				i++;
			}
			return max_znam;

		}
	}

}

//сложение
R& operator +(R r1, R r2) {
	R sum;
	int z;
	z = znam(r1, r2);
	if (z == r1.m && z == r2.m) {
		sum.n = r1.n + r2.n;
		sum.m = z;
	}
	if (z == r1.m && z != r2.m) {
		sum.n = r1.n + (r2.n * (z / r2.m));
		sum.m = z;
	}
	if (z != r1.m && z == r2.m) {
		sum.n = (r1.n * (z / r1.m)) + r2.n;
		sum.m = z;
	}
	if (z != r1.m && z != r2.m) {
		sum.n = (r1.n * (z / r1.m)) + (r2.n * (z / r2.m));
		sum.m = z;
	}
	return sum;
}
//минус
R& operator -(R r1, R r2) {
	R raz;
	int z;
	z = znam(r1, r2);
	if (z == r1.m && z == r2.m) {
		raz.n = r1.n - r2.n;
		raz.m = z;
	}
	if (z == r1.m && z != r2.m) {
		raz.n = r1.n - (r2.n * (z / r2.m));
		raz.m = z;
	}
	if (z != r1.m && z == r2.m) {
		raz.n = (r1.n * (z / r1.m)) - r2.n;
		raz.m = z;
	}
	if (z != r1.m && z != r2.m) {
		raz.n = (r1.n * (z / r1.m)) - (r2.n * (z / r2.m));
		raz.m = z;
	}
	return raz;
}
//умножение
R& operator *(R r1, R r2) {
	R umn;
	umn.n = r1.n * r2.n;
	umn.m = r1.m * r2.m;
	int g = gcd(umn.n, umn.m);
	umn.m = umn.m / g;
	umn.n = umn.n / g;
	return umn;
}
//деление
R& operator /(R r1, R r2) {
	R del;
	del.n = r1.n * r2.m;
	del.m = r1.m * r2.n;
	int g = gcd(del.n, del.m);
	del.m = del.m / g;
	del.n = del.n / g;
	return del;
}




int main()
{
	R r1(10, 100);
	R r2(3, 5);
	R r3(6, 9);
	cout << r1.n << "/" << r1.m <<"\n";
	cout << r2.n << "/" << r2.m << "\n";
	cout << r3.n << "/" << r3.m << "\n";
	if (r1 == r2) //проверка на равенство
		cout << r1.n << "/" << r1.m << " = " << r2.n << "/" << r2.m << "\n";
	else
		cout << r1.n << "/" << r1.m << " != " << r2.n << "/" << r2.m << "\n";
	R sum; //сложение
	sum = r1 + r2;
	cout << r1.n << "/" << r1.m << " + " << r2.n << "/" << r2.m << " = " << sum.n <<"/"<<sum.m << "\n";
	R raz; //разность
	raz = r1 - r2;
	cout << r1.n << "/" << r1.m << " - " << r2.n << "/" << r2.m << " = " << raz.n << "/" << raz.m << "\n";
	r1 *= r3; //проверка оператора умножить-равно
	cout << r1.n << "/" << r1.m << "\n"; 
	r2 *= 3; // проверка домножения на натуральное число
	cout << r2.n << "/" << r2.m << "\n";
	R r4 = r2 * r3; //проверка оператора умножить
	cout << r4.n << "/" << r4.m << "\n";
	R r5 = r2 / r3; //проверка оператора делить
	cout << r5.n << "/" << r5.m << "\n";
	
}