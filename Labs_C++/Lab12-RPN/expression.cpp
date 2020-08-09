#include <iostream>
#include <string>
#include "expression.h"
using namespace std;

expression::expression() : symbol(""), priority(0)
{
	type = expression_type::constant;
}

expression::expression(string element) : symbol(element), priority(0)
{
	if (element == "(" || element == ")")
	{
		priority = 1; type = expression_type::bracket;
	}
	else if (element == "+" || element == "-")
	{
		priority = 2;  type = expression_type::math_operator;
	}
	else if (element == "*" || element == "/")
	{
		priority = 3; type = expression_type::math_operator;
	}
	else
	{
		type = expression_type::constant;
	}
}

bool operator>(const expression& e1, const expression& e2)
{
	return (e1.priority > e2.priority);

}

bool operator<(const expression& e1, const expression& e2)
{
	return (e1.priority < e2.priority);

}