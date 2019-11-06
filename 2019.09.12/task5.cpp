// Написать функцию удаляющую из целочисленного массива все четные элементы. 
#include <iostream>

using namespace std;
int del(int n, int *&M) {
    int sum = n;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if ( *(M + i) % 2 == 0 ) sum--;
    }
    int* M1 = new int[sum];
    for (int i = 0; i < n; i++) {
    if ( *(M + i) % 2 != 0) {
        *(M1 + l) = *(M + i);
        l++;
        
            }
        
        }
    for (int i = 0; i < sum; i++) cout << *(M1 + i);
}
int main()
{
  int n;
  cin >> n;
  int* M = new int[n];
  for (int i = 0; i < n; i++) cin >> *(M + i);
  del(n, M);
}
