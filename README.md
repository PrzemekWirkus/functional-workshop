Functional workshop
===================

Simple set of workshop examples / exersices to practise functional programming in C++, C++1 (with a touch of STL and BOOST)

Prerequisites
===================
* Installed Git client. Get git client from here: http://git-scm.com/downloads
* Installed GCC toolchain with C++11 support (-std=c++11 gcc switch).
 * Get Windows GCC (MginGW) with C++11 for example from here: http://tdm-gcc.tdragon.net/download

Useful links
===================
* **std:for_each**: http://en.cppreference.com/w/cpp/algorithm/for_each
* **std::bind**: http://en.cppreference.com/w/cpp/utility/functional/bind
 * **std::placeholders**: http://en.cppreference.com/w/cpp/utility/functional/placeholders
* **Lambda expression**: http://en.cppreference.com/w/cpp/language/lambda
* **std::function**: http://en.cppreference.com/w/cpp/utility/functional/function
* **std::mem_fn**: http://en.cppreference.com/w/cpp/utility/functional/mem_fn
* **ptr_fun**: http://en.cppreference.com/w/cpp/utility/functional/ptr_fun

Usage
===================

* clone this repository to your computer:
```
$ git clone https://github.com/PrzemekWirkus/functional-workshop/
$ cd functional-workshop
```

* Make sure you have installed GCC with C++11 support (switch -std=c++1) should be available.
 * Use Makefile in this project to check your compiler's compatibility:
```
$ make testconf
g++ -c -o testconf.o src/testconf.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o testconf testconf.o -I./src -std=c++11 -fdiagnostics-color=always
```
If project was compiled without any issues make will produce executable in your working folder (in our case testconf.exe):
```
$ ls
LICENSE  Makefile  README.md  src  testconf.exe  testconf.o
```
You can execute testconf application to get simple resuts produced using C++11 code:
```
$testconf.exe
Lambda function call!

Found .org domains:
http://mbed.org
```
 * If you have problems compiling your project make sure GCC in in your path:
```
$ g++
g++: no input files
```
 * if not, please use CDIR makefile variable to set absolute path to compiler:
In below example we've installed Windows TDM-GCC 4.9.2 compiler in c:/Work/toolchains/tdm-gcc-4.9.2 direcotry and we are setting c:/Work/toolchains/tdm-gcc-4.9.2/bin directory 
```
$  make testconf CDIR=c:/Work/toolchains/tdm-gcc-4.9.2/bin/
c:/Work/toolchains/tdm-gcc-4.9.2/bin/g++ -c -o testconf.o src/testconf.cpp -I./src -std=c++11 -fdiagnostics-color=always
c:/Work/toolchains/tdm-gcc-4.9.2/bin/g++ -o testconf testconf.o -I./src -std=c++11 -fdiagnostics-color=always
```
* You can build all files just by typing:
```
$ make
g++ -c -o testconf.o src/testconf.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o testconf testconf.o -I./src -std=c++11 -fdiagnostics-color=always
g++ -c -o closure1.o src/closure1.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o closure1 closure1.o -I./src -std=c++11 -fdiagnostics-color=always
g++ -c -o closure2.o src/closure2.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o closure2 closure2.o -I./src -std=c++11 -fdiagnostics-color=always
g++ -c -o bind.o src/bind.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o bind bind.o -I./src -std=c++11 -fdiagnostics-color=always
g++ -c -o examples.o src/examples.cpp -I./src -std=c++11 -fdiagnostics-color=always
g++ -o examples examples.o -I./src -std=c++11 -fdiagnostics-color=always
```
Exercises
===================
All source code is in directory src/ in repository:
```
\functional-workshop
    \src
        closure1.cpp
        closure2.cpp
        bind.cpp
        examples.cpp
    Makefile
```
* Please uncomment task code before implementing.
Task source code will be between comments:
```c
/** UNCOMMENT TASK 1

... Task source code with unit test checks

UNCOMMENT */
```

* Closure1 - practise functors.
```
$ make closuse1
```
* Closure2 - practise lambda functions (you will mainly replace closure1 examples with lambda semantics).
```
$ make closuse2
```
* bind - use bind to create new functions from existing ones.
```
$ make bind
```
* exampels - few example susing STL and functional programming.
```
$ make examples
```
# Solution
This repository contains solution for each task under 'soultion' branch.
Please use:
```
$ git checkout solution
```
to switch to branch with solutions and 
```
$ git checkout master
```
to work on your answers. 
Note: you can use git stash to stash your changes in master (exercise branch) before switching to 'solution' branch.
