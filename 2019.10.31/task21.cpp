//На вещественную ось брошено N отрезков. Найти максимальное по включению множество непересекающихся отрезков.

#include <iostream>
#include <cmath>
using namespace std;

struct section {
	int x1, x2, l;
};

void quicksort(struct section* s, int low, int high) {
	int l = low; int h = high;
	int X = s[(low + high) / 2].x2;
	while (l <= h) {
		while (s[l].x2 < X) {
			l++;
		}
		while (s[h].x2 > X) {
			h--;
		}
		if (l <= h) {
			struct section t = s[l];
			s[l] = s[h];
			s[h] = t;
			l++;
			h--;
		}
		if (high > l) {
			quicksort(s, l, high);
		}
		if (h > low) {
			quicksort(s, low, h);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	section* s = new section[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i].x1;
		cin >> s[i].x2;
		if (s[i].x1 > s[i].x2) {
			swap(s[i].x1, s[i].x2);
		}
		s[i].l = abs(s[i].x2 - s[i].x1);
	}
	quicksort(s, 0, n - 1);
	int count = 0;
	for (int i = 1, z; i < n; i++, z = 0) {
		for (int j = 0; j < i; j++) {
			if (s[i].x1 > s[j].x2) {
				z = 1;
			}
			else z = 0;
		}
		if (z == 1) {
			count++;
			cout << endl;;
			cout << s[i].x1 << " " << s[i].x2;

		}
	}
	cout << endl;
	cout << count;
}
