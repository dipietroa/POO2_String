
#include "cstring.h"
#include <stdio.h>
#include <string.h>
#include <cfloat>
#include <cmath>
#include <stdlib.h>
#include <stdexcept>

#define END_OF_STR '\0'

using namespace std;

int abs(int i){
    return i < 0 ? -i : i;
}

void String::constructString(const char * const str){
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

bool String::equals(const String &str) const{
    return equals(str._str);
}

bool String::equals(const char* const str) const{
    if(_size != strlen(str))
        return false;
    for(int i = 0; i < _size; i++){
        if(_str[i] != str[i])
            return false;
    }
    return true;
}

bool String::operator == (const String &str) const{
    return equals(str);
}

bool String::operator == (const char* const str) const{
    return equals(str);
}

unsigned int String::size() const{
    return _size;
}

void String::append(const char* const other){
    char* buffer = new char[_capacity + strlen(other)];
    strcpy(buffer, _str);
    strcat(buffer, other);
    buffer[_size + strlen(other)] = END_OF_STR;
    
    delete[] _str;
    constructString(buffer);
}

void String::append(const char& b){
    const char str[2] = {b, END_OF_STR};
    this->append(str);
}

void String::append(const String& b){
    this->append(b._str);
}

String& String::operator +=(const String& b){
    this->append(b);
    return *this;
}

String& String::operator +=(const char* const b){
    this->append(b);
    return *this;
}

String& String::operator +=(const char& b){
    this->append(b);
    return *this;
}

String operator+(String a, const String &b){
    a.append(b);
    return a;
}

String operator+(String a, const char* const b){
    a.append(b);
    return a;
}

String operator+(String a, const char &b){
    a.append(b);
    return a;
}

String operator+(const char &b, String a){
    String c(b);
    c.append(a);
    return c;
}

char& String::at(int index) const{
    if(index >= this->size())
        throw out_of_range("out of range!");
    return _str[index];
}

char& String::operator[](int index) const{
    return this->at(index);
}

const char* String::operator=(const char* const str) {
    delete[] _str;
    constructString(str);
    return _str;
}

String String::substr(int from, int to) const {
    char clone[_capacity];
    strcpy(clone, _str);
    clone[to] = END_OF_STR;
    char * str = clone;
    str += from;
    return String(str);
}
