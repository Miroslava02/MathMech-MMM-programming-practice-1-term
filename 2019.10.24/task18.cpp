//  Написать программу поиска k-ой порядковой статистики, основанный на Qsort

#include <iostream>

using namespace std;


long int quicksort(long int* arr, int low, int high, int k) {
	int y = low, z = high;
	long int x = arr[(low + high) / 2];
	while (y <= z) {
		while (arr[y] < x) {
			y++;
		}
		while (arr[z] > x) {
			z--;
		}
		if (y <= z) {
			swap(arr[y], arr[z]);
			y++;
			z--;
		}
	}
	if (low <= k && k <= z) {
	      return quicksort(arr, low, z, k);
    }
	if (y <= k && k <= high) {
		return quicksort(arr, y, high, k);
	}
	return arr[k];
}

int main()
{
	int n, k;
	cout << "enter the length of the array ";
	cin >> n;
	cout << "enter k ";
	cin >> k;
	long int* arr = new long int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int answer;
	answer = quicksort(arr, 0, n-1, k-1);
	cout << answer;
}
