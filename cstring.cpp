
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
    this->_str = new char[_capacity];
    strcpy(this->_str, str);
    this->_str[_size] = END_OF_STR;
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
    return _str;
}

unsigned int String::size() const{
    return _size;
}

char& String::operator[](int index) const{
    if(index >= this->size())
        throw std::out_of_range(String(index));

    return _str[index];
}

const char* String::operator=(const char* str) {
    delete[] _str;
    constructString(str);
    return _str;
}

String String::substr(int from, int to) const {
    char* clone = new char[size()];
    strcpy(clone, _str);
    clone += from;
    clone[to] = END_OF_STR;
    return String(clone);
}
