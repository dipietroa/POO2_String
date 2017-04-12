
#include "cstring.h"
#include <stdio.h>
#include <string.h>
#define END_OF_STR '\0'

String::String(){
    _size = 0;
    _capacity = 1;
    _str = new char[_capacity];
    _str[_size] = END_OF_STR;
}
String::String(const char*& str){
    _size = strlen(str);
    _capacity = _size + 1;
    this->_str = new char[_capacity];
    strcpy(this->_str, str);
    this->_str[_size] = END_OF_STR;
}
String::String(const char& chr){
    _size = 1;
    _capacity = _size + 1;
    _str = new char[_capacity];
    _str[0] = chr;
    _str[_size] = END_OF_STR;
}
String::String(const String& str){
    _size = str._size;
    _capacity = str._capacity;
    _str = new char[_capacity];
    strcpy(_str, str._str);
    _str[_size] = END_OF_STR;
}
String::String(const int& entier){
    //const char num =
}
String::String(const float& reel){
    
}
String::String(const bool& booleen){
    const char * bln = booleen ? "true" : "false";
    _size = strlen(bln);
    _capacity = _size + 1;
    _str = new char[_capacity];
    strcpy(_str, bln);
    _str[_size] = END_OF_STR;
}
String::~String(){
    if (this->_str != NULL){
        delete[] this->_str;
        this->_str = NULL;
    }
}

String::operator const char*() const{
    return _str;
}

unsigned int String::size() const{
    return _size;
}
