#ifndef RANDOMNUMBERS_H_
#define RANDOMNUMBERS_H_

#include <iostream>


class RandomNumbers
{
public:
	void SetRandomValues(int, int);
	void GetRandomValues();
	int GetVar1();
	int GetVar2();
	int GetVar3();

private:
	int var1;
	int var2;
	int var3;
};

#endif /* RANDOMNUMBERS_H_ */
