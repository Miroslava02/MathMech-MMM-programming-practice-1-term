// Написать функцию сортировки массива, использующую указательную арифметику вместо обращения по индексам
#include <iostream>

using namespace std;
int sort (int n){
int* M = new int[n];
for (int i = 0; i < n; i++) {
    cin >> *(M + i);
}
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
    if (*(M + j) > *(M + j + 1)) {
       int temp = *(M + j);
       *(M + j) = * (M + j + 1);
       *(M + j + 1) = temp;
    }
    }
}


for (int i = 0; i < n; i++) {
        cout << *(M + i);
}
}
int main() {
int n;
cin >> n;
sort(n);
return 0;
}
