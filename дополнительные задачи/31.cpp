/*(* - задача на дополнительные баллы, без дедлайна +15б)
Реализовать универсальный поиск глобального максимума методом имитации отжига
*/
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
const double pi = 3.14;
const int D = 1;                // размерность
const int repeat = 10;      // повторения
const double tend = 1;         
const double tstart = 10;      

struct part
{
	double val;                 
	double left, right;                
};

struct argument              
{
	part c[D];
};



double f1(argument v)    
{
	double ampl1 = (1+ abs(sin(v.c[0].val / 8)));
	double ampl2 = (abs(cos(v.c[0].val + (abs(cos(v.c[0].val)) + 1))) * pi + 1) * 0.5;

	return ampl1 * (3 * sin(v.c[0].val * (abs(cos(v.c[0].val + pi / 3) / 5 + 1))) + ampl2 * cos(v.c[0].val * 20));
}



int sign(double x)           
{
	if (x > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

double DT(int step)   
{
	return tstart * pow(0.95, step);
}

argument randomize(argument v, double T)  
{
	double a_i = 0;
	double b_i = 0;
	double x = 0;
	argument temp;

	for (int i = 0; i < D; i++)
	{
		do
		{
			a_i = (double)(rand()) / RAND_MAX;
			b_i = sign(a_i - 0.5) * T * (pow(1 + 1 / T, abs(2 * a_i - 1)) - 1);
			x = v.c[i].val + b_i * (v.c[i].right - v.c[i].left);
		} while (x < v.c[i].left || x > v.c[i].right);
		temp.c[i].val = x;
		temp.c[i].left = v.c[i].left;
		temp.c[i].right = v.c[i].right;
	}

	return temp;
}

bool event(double chance) 
{
	double event = (double)(rand()) / RAND_MAX;

	if (event < chance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double transition(double dE, double temp) 
{
	return exp(-dE / temp);
}

argument newposition(double (*f)(argument), argument v_old, double T)
{
	double dE = 0, E_old = f(v_old);
	argument v_new;

	do
	{
		v_new = randomize(v_old, T);
		dE = E_old - f(v_new);
	} while (!event(transition(dE, T)));

	return v_new;
}

std::ostream& operator<< (std::ostream& cout, argument x)
{
	cout << "{";
	for (int i = 0; i < D; i++)
	{
		cout << x.c[i].val;
		if (i < D - 1)
		{
			cout << ", ";
		}
	}
	cout << "}";

	return cout;
}

void initialisation(argument& v_start)
{
	cout << "left and right border of searching area";
	cout << endl;
	for (int i = 0; i < D; i++)
	{
		cin >> v_start.c[i].left >> v_start.c[i].right;
		v_start.c[i].val = v_start.c[i].left + ((double)(rand()) / RAND_MAX) * (v_start.c[i].right - v_start.c[i].left);
	}
}

double global_max(double (*f)(argument), argument start, argument& v_max)
{
	argument v;
	int step = 0;
	double max = 0, val = 0, T = tstart;

	max = f(start);
	v = start;
	while (T > tend)
	{
		step++;
		T = DT(step);
		v = newposition(f, v, T);
		val = f(v);
		if (max < val)
		{
			max = val;
			v_max = v;
		}
	}

	return max;
}

int main()
{
	argument start, max, precise;
	double precise_max_value = 0, max_value = 0;
	srand(time(0));
	initialisation(start);
	max_value = f1(start);
	for (int i = 0; i < repeat; i++)
	{
		max_value = global_max(f1, start, max);
		if (max_value > precise_max_value || i == 0)
		{
			precise_max_value = max_value;
			precise = max;
		}
	} 
	cout << " max point " << precise;
	cout << endl;
	cout << "max value " << precise_max_value;
	cout << endl;
}