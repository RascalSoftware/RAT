//============================================================================
// Name        : functionOctave_new.cpp
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
#include <vector>

using namespace std;
using namespace octave;

int octaveCallerFunction() {

	cout << "Function start:" << endl;

	static int started = 0;
	static interpreter interpreter;

	cout << "Started: " << started << endl;

	// check to see if the interpreter has started
	// and initialise it if not.
	if (started == 0) {
		interpreter.initialize_history(false);
		interpreter.initialize();
		interpreter.execute();
		string path = "/home/arwel/eclipseWorkspace_new/functionOctave_new/src";
		octave_value_list p;
		p(0) = path;
		octave_value_list o1 = octave::feval ("addpath", p, 1);
		cout << "In interpreter initialise loop" << endl;
	    started = 1;
	}

    vector<double> vi = {10, 20, 30, 40};
    double bulkIn = 2.073e-6;
    double bulkOut = 6.35e-6;

    Matrix Ai(vi.size(),1);

    for (unsigned int i; i < vi.size(); i++) {
    	Ai(i) = vi.at(i);
        cout << "Ai(i):" << Ai(i) << endl;
    }

    // Construct Octave input
    octave_value_list in;
    in(0) = Ai;
    in(1) = octave_value(bulkIn);
    in(2) = octave_value(bulkOut);

    interpreter.execute();
    octave_value_list vo = octave::feval ("myFunction", in, 1);

    // Print out result of Octave output
    if (vo.length() > 0)
      cout << "Output is " << vo(0).matrix_value(0) << endl;
    else
      cout << "Output is invalid" << endl;

    return 0;

    /*Matrix v = out(0).matrix_value();
    Array<double> rv = v.as_row();  //Maybe easier to deal with variable sized output as a vector?? (m always = 3)

    // Pointer to start of our row vector
    double *s = rv.fortran_vec();

    octave_idx_type num = rv.dim2();
    int n = num;			// length of the row vector

    cout << "Number of elements is  " << n		// check we get the right value for n
    	<< endl;

    vector<double> vs(num);    // eventually going to put the elements in here....

    // print the values in the array pointed to by s
    for (int i=0; i<n; i++) {
    	cout << "element number "<< i << " is " <<*(s + i) << endl;
     }
    cout << endl;

    return 0;*/
}

