
#include "cstring.h"
#include <stdio.h>
#include <string.h>
#include <cfloat>
#include <cmath>
#include <stdlib.h>
#include <stdexcept>

#define END_OF_STR '\0'

int abs(int i){
    return i < 0 ? -i : i;
}

void String::constructString(const char * str){
    _size = strlen(str);
    _capacity = _size + 1;
    _str = new char[_capacity];
    strcpy(_str, str);
    _str[_size] = END_OF_STR;
}
String::String() : String(""){}

String::String(const char* str){
    constructString(str);
}
String::String(const char& chr){
    char str[2] = {chr, END_OF_STR};
    constructString((const char *)str);
}

String::String(const String& str) : String(str._str){}

String::String(const bool& booleen) : String(booleen ? "true" : "false"){}

String::String(const int& entier){
    char str[(int)log10(abs(entier)) + 2];
    sprintf(str, "%d", entier);
    constructString((const char *)str);
}
String::String(const double& reel){
    char str[3 + DBL_MAX_10_EXP - DBL_MIN_EXP];
    sprintf(str, "%f", reel);
    constructString((const char *)str);
}

String::~String(){
    if (_str != NULL){
        delete[] _str;
    }
}

String::operator const char*() const{
    return (const char *)_str;
}

bool String::operator == (const String &str) const{
    //Comparaison des deux chaînes, la capacité n'a pas
    //à être comparée selon nous.
    //return str._str == _str;
    if(_size != str._size)
        return false;
    for(int i = 0; i < _size; i++)
        if(_str[i] != str._str[i])
            return false;
    return true;
}

unsigned int String::size() const{
    return _size;
}

String& String::operator +=(const String& b){
    char* buffer = new char[_capacity + b._size];
    strcpy(buffer, _str);
    strcat(buffer, b._str);
    
    delete[] _str;
    constructString(buffer);
    
    return *this;
}

String& String::operator +=(const char* b){
    String str(b);
    return *this += str;
}

String& String::operator +=(const char& b){
    String str(b);
    return *this += str;
}

String operator+(String a, const String &b) {
    a += b;
    return a;
}

String operator+(String a, const char* b) {
    a += b;
    return a;
}

String operator+(String a, const char &b) {
    a += b;
    return a;
}

char& String::operator[](int index) const{
    //if(index >= this->size())
        //throw std::out_of_range();

    return _str[index];
}

const char* String::operator=(const char* str) {
    delete[] _str;
    constructString(str);
    return _str;
}

String String::substr(int from, int to) const {
    char* clone = new char[_size];
    strcpy(clone, _str);
    clone += from;
    clone[to] = END_OF_STR;
    return String(clone);
}
