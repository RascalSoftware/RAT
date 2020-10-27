//============================================================================
// Name        : eclipseCaller.cpp
// Author      : Arwel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <oct.h>
#include <octave.h>
#include <parse.h>
#include <interpreter.h>

using namespace std;

int main(void) {

	std::cout << "Hello World" << std::endl;

	octave::interpreter interpreter;


	int n = 2;
	Matrix a_matrix = Matrix (n,n);

	for (octave_idx_type i=0; i < n; i++)
		for (octave_idx_type j = 0; j<n; j++)
			a_matrix(i,j) = (i + 1) * 10 + (j + 1);

	std::cout << a_matrix;


	return 0;
}

