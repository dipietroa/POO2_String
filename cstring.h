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
        void constructString(const char * str);
    public:
        String();
        String(const char * str);
        String(const String& str);
        String(const char& chr);
        String(const int& entier);
        String(const double& reel);
        String(const bool& booleen);
        ~String();
        operator const char*() const;
        bool operator == (const String &str) const;
        bool operator == (const char* const str) const;
        friend String operator+(String a, const String &b);
        friend String operator+(String a, const char *b);
        friend String operator+(String a, const char &b);
        friend String operator+(const char &b, String a);
        String& operator+=(const String &b);
        String& operator+=(const char *b);
        String& operator+=(const char &b);
        void append(const char* other);
        void append(const char& b);
        void append(const String& b);
        bool equals(const String &str) const;
        bool equals(const char* const str) const;
        unsigned int size() const;
        char& operator[](int index) const;
        char& at(int index) const;
        const char* operator=(const char* str);
        String substr(int from, int to) const;
};

#endif	/* CSTRING_H */

