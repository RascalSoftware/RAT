/*
 * addNumbers.h
 *
 *  Created on: 8 Jan 2021
 *      Author: root
 */

#ifndef ADDNUMBERS_H_
#define ADDNUMBERS_H_

class addNumbers {

public:
	int number1;
	int number2;
	int answer;

	void setNumbers(int n1, int n2);
	void findSum();

};

// Member functions
// (no need for constructor
// because the attributes are
// defined in the class definition

void addNumbers::setNumbers(int n1, int n2) {
	number1 = n1;
	number2 = n2;
}

void addNumbers::findSum() {
	answer = number1 + number2;
}


#endif /* ADDNUMBERS_H_ */
