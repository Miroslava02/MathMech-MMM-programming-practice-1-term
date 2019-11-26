//Написать программу, находящую разложение натурального числа в сумму натуральных квадратов, с наименьшим числом слагаемых

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int  a, b, isch, ferm;
	cin >> isch; // чтение исходного числа
	a = sqrt(isch);
	b = isch - a * a;
	ferm = (isch - 1) % 4; //теорема ферма-эйлера
	if (b == 0) {
		cout << isch << " = " << a << "^2";
	}
	else if (ferm == 0) {
		
	}
	
}

