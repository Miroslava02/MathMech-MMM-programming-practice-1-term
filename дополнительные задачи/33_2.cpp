/*(* - задача на дополнительные баллы, без дедлайна +10б)
Дана таблица  размером n * m. 
Требуется найти в ней такую прямоугольную область , состоящую только из нулей, 
и среди всех таких — имеющую наибольшую площадь. Решение должно быть не медленнее чем O(n*m).
*/
// Таблица из нулей и единиц, элементы нумеруются с нуля.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;

int main()
{
	int sto, str;
	cin >> sto >> str;
	vector < vector<int> > a(str, vector<int>(sto));
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < sto; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < sto; j++) {
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	int matrix = 0;

	vector<int> lim1(sto, -1), lim2(sto), lim3(sto);
	stack<int> st;
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < sto; ++j) {
			if (a[i][j] == 1) {
				lim1[j] = i;
			}
		}
		while (!st.empty()) {
			st.pop();
		}
		for (int j = 0; j < sto; ++j) {
			while (!st.empty() && lim1[st.top()] <= lim1[j]) {
				st.pop();
			}
			if (st.empty()) {
				lim2[j] = -1;
			}
			else {
				lim2[j] = st.top();
			}
			st.push(j);
		}
		while (!st.empty()) {
			st.pop();
		}
		for (int j = sto - 1; j >= 0; --j) {
			while (!st.empty() && lim1[st.top()] <= lim1[j]) {
				st.pop();
			}
			if (st.empty()) {
				lim3[j] = sto;
			}
			else {
				lim3[j] = st.top();
			}
			st.push(j);
		}
		for (int j = 0; j < sto; ++j)
			if (matrix > (i - lim1[j])* (lim3[j] - lim2[j] - 1)) {
				matrix = matrix;
			}
			else {
				matrix = (i - lim1[j]) * (lim3[j] - lim2[j] - 1);
			}
	}

	cout << "answer: " << matrix;
}