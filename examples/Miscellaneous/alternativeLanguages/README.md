## Alternative Custom Model Languages

### Compile Instructions for M1 OSX  
```
clang -c customBilayer.cpp -o customBilayer.o -std=c++11 -arch x86_64
clang -shared customBilayer.o -o customBilayer.dylib -arch x86_64 -lc++ 
```

### Compile Instructions for Linux
```
g++ -fPIC -c customBilayer.cpp -o customBilayer.o -std=c++11
g++ -shared customBilayer.o -o customBilayer.so 
```

### Compile Instructions for Windows with MSVC
Ensure that the correct version of cl.exe is used by opening the x64 
command prompt for MSVC
```
cl /EHsc /LD customBilayer.cpp
```
