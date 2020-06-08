#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

int Search(int* array, int size, int searchFor)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == searchFor)
			return array[i];
	}
	return 0;
}

void FillArrayRnd(int* array, int size, int min, int max)
{
	default_random_engine generator(time(0));
	uniform_int_distribution<int> random(min, max);
	for (int i = 0; i < size; ++i)
	{
		array[i] = random(generator);
	}
}

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void QuickSort(int* array, int size)
{
	const int maxStack = 1024;
	int i, j, lb, ub, lbstack[maxStack], ubstack[maxStack], stackpos = 1, ppos, pivot;
	lbstack[1] = 0;
	ubstack[1] = size - 1;
	do
	{
		lb = lbstack[stackpos];
		ub = ubstack[stackpos];
		stackpos--;
		do
		{
			ppos = (lb + ub) >> 1;
			i = lb;
			j = ub;
			pivot = array[ppos];
			do
			{
				while (array[i] < pivot)
					i++;
				while (pivot < array[j])
					j--;

				if (i <= j)
				{
					Swap(&array[i], &array[j]);
					i++;
					j--;
				}
			} while (i <= j);
			if (i < ppos)
			{
				if (i < ub)
				{
					stackpos++;
					lbstack[stackpos] = i;
					ubstack[stackpos] = ub;
				}
				ub = j;
			}
			else
			{
				if (j > lb)
				{
					stackpos++;
					lbstack[stackpos] = lb;
					ubstack[stackpos] = j;
				}
				lb = i;
			}
		} while (lb < ub);
	} while (stackpos != 0);
}
void Print(int* array, int num)
{
	cout << "First " << num << " elements : ";
	for (int i = 0; i < num; ++i)
		cout << array[i] << " ";
	cout << endl;
}

int Partition(int* array, int start, int end)
{
	int x = array[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
		if (array[j] <= x)
		{
			i++;
			Swap(&array[i], &array[j]);
		}
	Swap(&array[i + 1], &array[end]);
	return (i + 1);
}

void RecursiveQuickSort(int* array, int start, int end)
{
	if (start < end)
	{
		int q = Partition(array, start, end);
		RecursiveQuickSort(array, start, q - 1);
		RecursiveQuickSort(array, q + 1, end);
	}
}

int BinarySearch(const int* array, int value, int left, int right)
{
	while (right >= left)
	{
		int mid = (right + left) / 2;
		if (array[mid] == value)
			return mid;
		if (array[mid] > value)
			right = mid;
		if (array[mid] < value)
			left = mid + 1;
	}
	return -1;
}

int RecursiveBinarySearch(int* array, int value, int left, int right)
{
	int mid = (right + left) / 2;
	if (array[mid] == value)
		return mid;
	if (array[mid] > value)
		return RecursiveBinarySearch(array, value, left, mid);
	if (array[mid] < value)
		return RecursiveBinarySearch(array, value, mid + 1, right);
	return -1;
}

int main()
{
	int searchCheck[1000];
	FillArrayRnd(searchCheck, 1000, -500, 500);
	cout << "Linear search result: " << Search(searchCheck, 1000, 228) << endl;
	int testQuickSort[100];
	FillArrayRnd(testQuickSort, 100, -10, 10);
	Print(testQuickSort, 50);
	QuickSort(testQuickSort, 100);
	Print(testQuickSort, 50);
	int quickSortCheckRecursive[100];
	FillArrayRnd(quickSortCheckRecursive, 100, -10, 10);
	Print(quickSortCheckRecursive, 50);
	RecursiveQuickSort(quickSortCheckRecursive, 0, 99);
	Print(quickSortCheckRecursive, 50);
	int binarySearchCheck[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Binary search result: " << BinarySearch(binarySearchCheck, 5, 1, 8)
		<< endl;
	cout << "Recursive binary search result: "
		<< RecursiveBinarySearch(binarySearchCheck, 7, 0, 6) << endl;
}