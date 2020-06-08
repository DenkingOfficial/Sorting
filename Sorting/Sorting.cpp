#include <iostream>
#include <random>
#include <string>
#include <ctime>

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


int main()
{
	int searchCheck[1000];
	FillArrayRnd(searchCheck, 1000, -500, 500);
	cout << "Linear search result: " << Search(searchCheck, 1000, 228) << endl;
}