#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(string name, int amount) : name(name), amount(amount) {}
    bool operator >(const Person &g) const;
    bool operator ==(const Person &g) const;
    bool operator >=(const Person &g) const;
    bool operator <(const Person &g) const;
    bool operator <=(const Person &g) const;
    bool operator !=(const Person &g) const;
    
    // Operators for comparing with int
    bool operator <(int value) const;
    bool operator >(int value) const;
    bool operator <=(int value) const;
    bool operator >=(int value) const;
    bool operator ==(int value) const;
    bool operator !=(int value) const;
    
    // Friend functions for comparing int with Person
    friend bool operator <(int value, const Person &p);
    friend bool operator >(int value, const Person &p);
    friend bool operator <=(int value, const Person &p);
    friend bool operator >=(int value, const Person &p);
    friend bool operator ==(int value, const Person &p);
    friend bool operator !=(int value, const Person &p);
    
    int getAmount() const;
    friend ostream& operator <<(ostream &out, const Person &g);
private:
    string name;
    int amount;
};

bool Person::operator >(const Person &g) const {
    return amount > g.amount;
}

bool Person::operator ==(const Person &g) const {
    return amount == g.amount;
}

bool Person::operator >=(const Person &g) const {
    return amount >= g.amount;
}

bool Person::operator <(const Person &g) const {
    return amount < g.amount;
}

bool Person::operator <=(const Person &g) const {
    return amount <= g.amount;
}

bool Person::operator !=(const Person &g) const {
    return amount != g.amount;
}

// Operators for comparing with int
bool Person::operator <(int value) const {
    return amount < value;
}

bool Person::operator >(int value) const {
    return amount > value;
}

bool Person::operator <=(int value) const {
    return amount <= value;
}

bool Person::operator >=(int value) const {
    return amount >= value;
}

bool Person::operator ==(int value) const {
    return amount == value;
}

bool Person::operator !=(int value) const {
    return amount != value;
}

// Friend functions for comparing int with Person
bool operator <(int value, const Person &p) {
    return value < p.amount;
}

bool operator >(int value, const Person &p) {
    return value > p.amount;
}

bool operator <=(int value, const Person &p) {
    return value <= p.amount;
}

bool operator >=(int value, const Person &p) {
    return value >= p.amount;
}

bool operator ==(int value, const Person &p) {
    return value == p.amount;
}

bool operator !=(int value, const Person &p) {
    return value != p.amount;
}

int Person::getAmount() const {
    return amount;
}

ostream& operator <<(ostream &out, const Person &g) {
    out << g.name << ": " << g.amount;
    return out;
}

#endif 