// Lab_6_1.cpp
// Козубенко Андрій
// Лабораторна робота № 6.1 
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом.
// Варіант 10
// Ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using std::cout;
using std::endl;
using std::setw;

void CreateArray(int *c, const int LeftLimit, const int RightLimit, const int size);
void PrintArray(int *c, const int size);
void Sum(int* c, const int size, int &S, int &Number);
void Replace(int *c, const int size);

int main()
{
	srand((unsigned)time(NULL));

	int S = 0;
	int k = 0;
	int A = 15;
	int B = 85;
	const int n = 21;
	int c[n];

	CreateArray(c, A, B, n);
	PrintArray(c, n);
	Sum(c, n, S, k);
	Replace(c, n);
	PrintArray(c, n);

	cout << "Sum of elements replaced: " << setw(5) << S << endl;
	cout << "Number of elements replaced: " << setw(3) << k << endl;

	return 0;
}

void CreateArray(int *c, const int LeftLimit, const int RightLimit, const int size)
{
	for (int i = 0; i < size; i++)
	{
		c[i] = LeftLimit + rand() % (RightLimit - LeftLimit + 1);
	}
}

void PrintArray(int *c, const int size)
{
	cout << "c = " << "{";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << c[i];
		if (i != size - 1)
			cout << ",";
	}
	cout << " }\n" << endl;
}

void Replace(int *c, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (c[i] % 2 && c[i] % 13 != 0)
			c[i] = 0;
	}
}

void Sum(int *c, const int size, int &S, int &Number)
{
	for (int i = 0; i < size; i++)
	{
		if (c[i] % 2 && c[i] % 13 != 0)
		{
			S += c[i];
			Number++;
		}
	}
}
