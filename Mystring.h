//
// Created by ostatidie on 6/23/25.
//

#ifndef MYSTRING_H
#define MYSTRING_H



class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &obj);
    friend bool operator==(const Mystring &rhs, const Mystring &lhs);
    friend bool operator!=(const Mystring &rhs, const Mystring &lhs);
    friend bool operator<(const Mystring &rhs, const Mystring &lhs);
    friend bool operator>(const Mystring &rhs, const Mystring &lhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, int rhs);

private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring( Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    Mystring &operator+=(const Mystring &rhs);
    Mystring &operator*=(int rhs);
    Mystring &operator++();
    Mystring operator++(int);


    void display() const;

    int get_length() const;
    const char *get_str() const;
};



#endif //MYSTRING_H
