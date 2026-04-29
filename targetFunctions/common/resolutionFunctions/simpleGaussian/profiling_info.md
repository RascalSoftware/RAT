orsoTest4
Timing for 10000 runs 

|N |method | int time (sec) | +func time |error     |
|--|------|--------------|----|-----------|
| 1 |simple poly mexed |0.15| 0.42 |0.0418|
| 2 |simple poly Matlab |0.25| 6.75 |0.0418|
| 3 | point insertion| 1892.07 ||  4.6e-06 |
| 4 |point insertion, mexed | 69.1 | | 4.6e-06 |
| 5 |point line interpolation | 359.7 | 6.75 |0.00419|
| 6 |point spline interpolation | 53.8 | 6.75 |0.0048   |
| 7 |point interpolation, integrals calculated analytically, trivial summation | 3.3 | 6.75 | 0.00419 |
| 8 |point interpolation, integrals calculated analytically, trivial summation, 10^-3 Gaussian rejected|  1.6 | 6.75 | 0.00419|
| 9 |point interpolation, integrals calculated analytically, trivial summation, 10^-3 Gaussian rejected, mexed | 0.36 |0.42| 0.00419|
| 10 |trapezoid integration, MATLAB 10^-3 Gaussian rejected: |1.07 | 6.75 | 0.019|
| 11 | trapezoid integration,mexed 10^-3 Gaussian rejected: |0.145 | 0.42 | 0.019|
