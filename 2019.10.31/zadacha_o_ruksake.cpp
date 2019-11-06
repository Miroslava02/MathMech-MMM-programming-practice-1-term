//Решить непрерывную задачу о рюкзаке и доказать через матроиды корректность алгоритма.
//Формулировка задачи: дано N предметов, ni предмет имеет массу wi>0 и стоимость pi>0. Необходимо выбрать из этих предметов такой набор, чтобы суммарная масса не превосходила заданной величины W (вместимость рюкзака), а суммарная стоимость была максимальна.
//Непрерывный рюкзак: вариант задачи, в котором возможно брать любую дробную часть от предмета, при этом удельная стоимость сохраняется.

//
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
struct predmeti {
	int i;
	int x[10];
	int w, p;

};
int main()
{
	const int arr_size = 10;
	int sum = 0;
	predmeti x[arr_size];
	predmeti rukzak;
	rukzak.w = 11;
	cout << "r_size = " << rukzak.w << "\n";
	x[0].w = 1; x[0].p = 1;
	x[1].w = 2; x[1].p = 2;
	x[2].w = 3; x[2].p = 3;
	x[3].w = 4; x[3].p = 4;
	x[4].w = 5; x[4].p = 5;
	x[5].w = 6; x[5].p = 6;
	x[6].w = 7; x[6].p = 7;
	x[7].w = 9; x[7].p = 9;
	x[8].w = 9; x[8].p = 9;
	x[9].w = 9; x[9].p = 9;
	x[10].w = 9; x[10].p = 9;
	for (int i = 0; i <= arr_size; i++) { //сортируем предметы по стоимости
		for (int j = 0; j <= arr_size - i - 1; j++) {
			if (x[j].p < x[j + 1].p) {
				int temp = x[j].p;
				int temp2 = x[j].w;
				x[j].p = x[j + 1].p;
				x[j].w = x[j + 1].w;
				x[j + 1].p = temp;
				x[j + 1].w = temp2;
			}
		}
	}
	for (int i = 0; i <= arr_size; i++) {
		cout << i << "." << x[i].w << " " << x[i].p << "\n";
	}
	for (int i = 0; i <= arr_size; i++) {
		if (rukzak.w > x[i].w) { //если влезает целиком - берём целиком
			sum += x[i].p;
			rukzak.w -= x[i].w;
		}
		else {
			sum += (rukzak.w * x[i].p) / x[i].w; //берем ту часть, что влезает, и выходим
			break;
		}
	}
	cout << sum << "\n";

	


}

