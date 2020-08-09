#pragma once
#include <iostream>
#include <string>
using namespace std;

class expression
{
public:
	enum class expression_type { constant, math_operator, bracket };
private:
	string symbol;
	int priority;
	expression_type type;
public:
	expression();
	expression(string element);
	int check_priority() const { return priority; }
	expression_type check_type() const { return type; }
	string get_symbol() const { return symbol; }
	friend bool operator>(const expression& e1, const expression& e2);
	friend bool operator<(const expression& e1, const expression& e2);
};