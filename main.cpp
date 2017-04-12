/* 
 * File:   main.cpp
 * Author: Adrian
 *
 * Created on 11. avril 2017, 12:48
 */
#include <iostream>
#include <cstdlib>
#include "cstring.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    String str("bonjour");
    String str2("bonjour");
    int salut = 2;
    
    cout <<"\'"<< (str += str2) <<"\'"<< endl <<"\'"<< str.size() <<"\'"<< endl;
    return 0;
}

