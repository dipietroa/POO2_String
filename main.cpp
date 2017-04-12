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
    str[2] = 'b';
    String str2(-1000000000);
    str2 = str = "patate";
    str2 = str.substr(1, 4);
    int salut = 2;
    
    cout <<"\'"<< str <<"\'"<< endl <<"\'"<< str2 <<"\'"<< endl;
    return 0;
}

