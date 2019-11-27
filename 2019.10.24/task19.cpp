//Провести эксперимент, для сортировки выбором. Экспериментально определить отношение между сравнением и swap, при котором сравнения малы по сравнению  с перестановкой?  


#include <iostream>
#include <cstdlib>
#define Time_swap 0.1
#define Time_compare 0.001
using namespace std;


void selection(int* a, int n, double& c1, double& c2, double time_swap, double time_compare) {
	int min = 0;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			c2 += time_compare;
			if (a[j] < a[min]) {
				min = j;

			}

		}
		if (min != i) {
			swap(a[i], a[min]);
			c1 += time_swap;

		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
		b[i] = a[i];
	}
	double time_swap, time_compare;
	time_swap = Time_swap;
	time_compare = Time_compare;
	double c1 = 0, c2 = 0;
	selection (a, n, c1, c2, time_swap, time_compare);
	cout << "compare = " << c1 << " swap = " << c2;
}