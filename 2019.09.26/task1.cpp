//Напишите эффективную программу, находящую все числа длины n являющиеся палиндромами.

#include <iostream>
using namespace std;

long int a;
int N;


void palindrom(int n, long int a)
{

	if (n == 0)
	{
		int k = 1, l = 0;
		long int A = a;
		for (int i = 0; i < N / 2; i++)
		{
			l = l * 10 + ((A / k) % 10);
			k *= 10;
		}
		if (A % 10 == 0)
		{
			if (N % 2 == 0)
			{
				cout << a << "0" << l << "\n";
			}
			else
			{
				for (int s = 0; s < 10; s++)
					cout << a << s << "0" << l << "\n";
			}
		}
		else
		{
			if (N % 2 == 0)
			{
				cout << a << l << "\n";
			}
			else
			{
				for (int s = 0; s < 10; s++)
					cout << a << s << l << "\n";
			}
		}
	}
	else
	{
		for (int j = 0; j < 10; j++)
		{
			palindrom(n - 1, a * 10 + j);
		}
	}

}
int main()
{

	cin >> N;
	for (int i = 1; i < 10; i++)
	{
		palindrom((N - 2) / 2, i);
	}

	return 0;
}
