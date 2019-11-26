//Решить непрерывную задачу о рюкзаке

#include <iostream>
using namespace std;

void quicksort (double* w, double* s, int low, int high) // quicksort по удельной стоимости
{
	double x;
	double* u = new double[high + 1];
	for (int i = 0; i < high + 1; i++) {
		u[i] = s[i] / w[i]; 
	}
	int lo = low, h = high;
	x = u[(lo + h) / 2];
	while (lo < h) {
		while (u[lo] > x) {
			lo++;
		}
		while (u[h] < x) {
			h--;
		}
		if (lo <= h)
		{
			swap(u[lo], u[h]);
			swap(s[lo], s[h]);
			swap(w[lo], w[h]);
			lo++;
			h--;
		}
	} 
	if (low < h) quicksort(w, s, low, h);
	if (lo < high) quicksort(w, s, lo, high);
}
void backpack (double* w, double* s, int* a, int n, double& contr_w) {
	double sum = 0;
	quicksort(w, s, 0, n - 1);
	int last = 0;
	for (int i = 0; i < n; i++) {
		if (contr_w > w[i]) {
			sum = sum + s[i];
			contr_w =contr_w - w[i];
			a[i] = 1;
		}
		else
		{
			sum = sum + (contr_w / w[i] * s[i]);
			last = i;
			a[i] = 1;
			break;
		}
	}
	cout << sum << endl;
}
int main()
{
	int n;
	double contr_w;
	cout << "enter backpack size ";
	cin >> contr_w;
	cout << "enter number of items ";
	cin >> n;
	double* s = new double[n]; //цена
	double* w = new double[n]; //вес
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		cin >> s[i];
		a[i] = 0;
	};
	backpack(w, s, a, n, contr_w);
}