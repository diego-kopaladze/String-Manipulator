//
// Created by ostatidie on 6/23/25.
//
#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i{0}; buff[i] != '\0'; i++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring operator+(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i{0}; buff[i] != '\0'; i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

bool operator==(const Mystring &rhs, const Mystring &lhs) {
    return std::strcmp(rhs.str, lhs.str) == 0;
}

bool operator!=(const Mystring &rhs, const Mystring &lhs) {
    return std::strcmp(rhs.str, lhs.str) != 0;
}

bool operator<(const Mystring &rhs, const Mystring &lhs) {
    return std::strcmp(rhs.str, lhs.str) < 0;
}

bool operator>(const Mystring &rhs, const Mystring &lhs) {
    return std::strcmp(rhs.str, lhs.str) > 0;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];

    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);

    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring operator*(const Mystring &lhs, int rhs) {
    if (rhs <= 0)
        return Mystring{""};

    size_t buff_size = std::strlen(lhs.str) * rhs + 1;
    char *buff = new char[buff_size];
    buff[0] = '\0';  // Initialize to empty string

    for (int i = 0; i < rhs; ++i)
        std::strcat(buff, lhs.str);

    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    size_t new_size = std::strlen(this->str) + std::strlen(rhs.str) + 1;
    char *buff = new char[new_size];

    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);

    delete [] this->str;
    this->str = buff;

    return *this;
}

Mystring &Mystring::operator*=(int rhs) {
    if (rhs <= 0) {
        delete [] this->str;
        this->str = new char[1];
        this->str[0] = '\0';
        return *this;
    }

    size_t new_size = std::strlen(this->str) * rhs + 1;
    char *buff = new char[new_size];
    buff[0] = '\0';  // Start with empty string

    for (int i = 0; i < rhs; ++i) {
        std::strcat(buff, this->str);
    }

    delete [] this->str;
    this->str = buff;

    return *this;
}

Mystring &Mystring::operator++() {
    for (size_t i{0}; i < std::strlen(this->str); i++) {
        this->str[i] = std::toupper(this->str[i]);
    }
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring temp{*this};
    ++(*this);
    return temp;
}