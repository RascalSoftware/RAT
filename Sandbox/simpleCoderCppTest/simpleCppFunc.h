#if defined __cplusplus
extern "C" {
#endif
    
#ifndef SIMPLECPPFUNC_H_
#define SIMPLECPPFUNC_H_

using namespace std;

void simpleCppFunc(int input, int &output) {

	int myVal;

	std::cout << "Input is " << input << endl;

	myVal = input;
	output = myVal*2;

}

#endif /* SIMPLECPPFUNC_H_ */

#if defined __cplusplus
}
#endif
