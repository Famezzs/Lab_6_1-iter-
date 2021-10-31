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

void CreateRandArray(int *a, const int LeftLimit, const int RightLimit, const int size);
void PrintArray(int *a, const int size);
void Search(int *a, const int size, int &numbofel, int &S);
void Replace(int *a, const int number);
void Sum(const int element, int &S);
void PrintReplResult( const int S, const int numbofel);

int main()
{
	srand((unsigned)time(NULL));

	int A = 15;
	int B = 85;
	const int n = 21;
	int c[n];
	int S = 0; // сума елементів, що замінюються нулем
	int z = 0; // кількість елементів, що замінюються нулем

	CreateRandArray(c, A, B, n);
	PrintArray(c, n);
	Search(c, n, z, S);
	PrintArray(c, n);
	PrintReplResult(S, z);
}

void CreateRandArray(int *a, const int LeftLimit, const int RightLimit, const int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = LeftLimit + rand() % (RightLimit - LeftLimit + 1);
	}
}

void PrintArray(int *a, const int size)
{
	cout << "c = " << "{";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << a[i];
		if (i != size - 1)
			cout << ",";
	}
	cout << " }" << endl;
}

void Search(int *a, const int size, int &numbofel, int &S)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 && a[i] % 13 != 0)
		{
			Sum(a[i], S);
			Replace(a, i);
			numbofel++;
		}
	}
}

void Sum(const int element, int &S)
{
	S += element;
}

void PrintReplResult(const int S, const int numbofel)
{
	cout << "Sum of replaced elements = " << S << endl;
	cout << "Number of replaced elements = " << numbofel << endl;
}

void Replace(int *a, const int number)
{
	a[number] = 0;
}