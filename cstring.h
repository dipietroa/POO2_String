/* 
 * File:   cstring.h
 * Author: Adrian
 *
 * Created on 11. avril 2017, 12:49
 */

#ifndef CSTRING_H
#define	CSTRING_H

class String{
    private:
        unsigned int _capacity;
        unsigned int _size;
        char * _str;
    public:
        String();
        String(const char * str);
        String(const String& str);
        String(const char& chr);
        String(const int& entier);
        String(const double& reel);
        String(const bool& booleen);
        void constructString(const char * str);
        ~String();
        operator const char*() const;
        bool operator == (const String &str) const;
        friend String operator+(String a, const String &b);
        friend String operator+(String a, const char *b);
        friend String operator+(String a, const char &b);
        const String& operator+=(const String &b);
        const String& operator+=(const char *b);
        const String& operator+=(const char &b);
        unsigned int size() const;
        char& operator[](int index) const;
        const char* operator=(const char* str);
        String substr(int from, int to) const;
};

#endif	/* CSTRING_H */

