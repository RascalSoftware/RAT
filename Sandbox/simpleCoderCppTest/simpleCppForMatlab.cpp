//============================================================================
// Name        : simpleCppForMatlab.cpp
// Author      : Arwel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "simpleCppFunc.h"

using namespace std;

int main() {

	int out2;
	int value = 20;

	simpleCppFunc(value, out2);

	std::cout << out2;
	return 0;

}
