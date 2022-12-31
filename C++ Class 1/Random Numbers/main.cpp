#include <iostream>

#include "RandomNumbers.h"
using namespace std;

int main()
{
	int low;
	int high;
	cin >> low;
	cin >> high;

	RandomNumbers rn = RandomNumbers();
	rn.SetRandomValues(low, high);
	rn.GetRandomValues();

	return 0;
}