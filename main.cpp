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
    //Create all type of String
    String s1 = "bonjour";
    String s2('K');
    String s3 = 2;
    String s4(2.12345);
    String s5 = true;
    String s6(s1);
    
    cout << "Strings after instanciation: "
         <<"s4="<<s1<<','<<"s2="<<s2<<','<<"s3="<<s3<<','<<"s4="<<s4<<','
         <<"s5="<<s5<<','<<"s6="<<s6<<endl;

    s4 = s5;
    s1 = "aurevoir";
    s2 = 'D';

    cout << "Strings after affectation: "
         <<"s4=" <<s4<<','<<"s1="<<s1<<','<< "s2="<<s2<<endl;

    cout << endl;
    cout << "I make s2 + s1 = " << (s2 + s1) << " but s2 stills " << s2 << endl;
    cout << "But if I make s2 += \"oudou\" = " << (s2+="oudou") << " s2 is now: ";
    cout << s2 << endl;

    cout << endl;
    cout << "I make 'C' + s2 + 'E' = " << ('C' + s2 + 'E') << endl;
    cout << "I make \"Un \" + (s2 += s5) = " << ("Un " + (s2 += s5)) << endl;
    cout << "Now s2 = " << s2 << endl;

    cout << endl;
    cout << "I make s2 = s2.substr(3,9).substr(0,3) = " << (s2 = s2.substr(3,9).substr(0,3)) << endl;
    cout << "Now s2 = " << s2 << endl;

    cout << endl;
    cout << "I make s2 == \"dout\" = " << boolalpha << (s2 == "dout") << endl;
    cout << "I make s2 == s1 = " << boolalpha << (s2 == s1) << endl;

            
    return 0;
}

