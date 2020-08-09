#include <iostream>
#include <complex>
#include <string>
#include "linkedQueue.h"
#include "linkedStack.h"
#include "expression.h"
using namespace std;

//template <typename T>
//T rpn_value(string rpn_expression)
//{
//	static_assert(is_arithmetic<T>::value, "Arithmetic type required!");
//
//	string element;
//	stringstream iss(rpn_expression);
//	stringstream oss;
//
//	while (iss >> element)
//	{
//		cout << element << endl;
//		oss << element << " ";
//	}
//	cout << oss.str() << endl;
//
//	return T();
//}

template <typename T>
T string_to_num(string str) {
	return 0;
}

template <>
int string_to_num(string str) {
	return stoi(str);
}

template <>
double string_to_num(string str) {
	return stof(str);
}

template <typename T>
T rpn_value(string rpn_expression)
{
	static_assert(is_arithmetic<T>::value, "Arithmetic type required!");

	string element;
	stringstream iss(rpn_expression);
	linkedStack<T> stack;

	while (iss >> element) {
		try {
			T num = string_to_num<T>(element);
			stack.push(num);
		}
		catch (std::invalid_argument) {
			T num2 = stack.top();
			stack.pop();
			T num1 = stack.top();
			stack.pop();
			T result = 0;
			if (element == "+")
				result = num1 + num2;
			if (element == "-")
				result = num1 - num2;
			if (element == "/")
				result = num1 / num2;
			if (element == "*")
				result = num1 * num2;
			stack.push(result);
		}
	}

	T result = stack.top();
	stack.pop();

	return result;
}

string rpn(string symbolic_expression) {

	string element;
	stringstream iss(symbolic_expression);
	stringstream oss;
	
	linkedStack<expression> stack;

	while (iss >> element) {
		expression temp = expression(element);
		if (temp.check_type() == expression::expression_type::constant)
			oss << element << " ";
		if (temp.check_type() == expression::expression_type::math_operator) {
			if (stack.isEmptyStack() == true)
				stack.push(temp);
			else if (temp > stack.top())
				stack.push(temp);
			else {
				while (stack.top().check_priority() >= temp.check_priority()) {
					oss << stack.top().get_symbol() << " ";
					stack.pop();
					if (stack.isEmptyStack())
						break;
					if (stack.top() < temp)
						stack.push(temp);
				}
				stack.push(temp);
			}
		}
		if (temp.check_type() == expression::expression_type::bracket) {
			if (temp.get_symbol() == "(")
				stack.push(temp);
			else {
				while (stack.top().get_symbol() != "(") {
					oss << stack.top().get_symbol() << " ";
					stack.pop();
				}
				stack.pop();
			}
		}
	}

	while (stack.isEmptyStack() == false) {
		oss << stack.top().get_symbol() << " ";
		stack.pop();
	}

	return oss.str();
}

int main()
{
	std::cout << std::endl << " --------------------- STAGE_1 (3 Pts) --------------------- " << std::endl;

	// Comment after converting linkedQueue to template
	/*
	linkedQueue q;

	q.addQueueBack(3);
	q.addQueueBack(4);
	q.addQueueBack(5);
	q.addQueueFront(2);
	q.addQueueFront(1);

	cout << q << endl;
	cout << "Front value: " << q.front() << endl;
	cout << "Rear value: " << q.back() << endl;

	while (!q.isEmptyQueue())
	{
		q.deleteQueue();
	}

	cout << q << endl;*/
	

	// Uncomment after converting linkedQueue to template
	
	linkedQueue<int> q1;

	q1.addQueueBack(3);
	q1.addQueueBack(4);
	q1.addQueueBack(5);
	q1.addQueueFront(2);
	q1.addQueueFront(1);

	cout << q1 << endl;
	cout << "Front value: " << q1.front() << endl;
	cout << "Rear value: " << q1.back() << endl;

	while (!q1.isEmptyQueue())
	{
		q1.deleteQueue();
	}

	cout << q1 << endl;
	cout << endl;

	linkedQueue<complex<double>> q2;

	q2.addQueueBack(complex < double>(3,1));
	q2.addQueueBack(complex < double>(4,1));
	q2.addQueueBack(complex < double>(5,1));
	q2.addQueueFront(complex < double>(2,1));
	q2.addQueueFront(complex < double>(1,1));

	cout << q2 << endl;
	cout << "Front value: " << q2.front() << endl;
	cout << "Rear value: " << q2.back() << endl;

	while (!q2.isEmptyQueue())
	{
		q2.deleteQueue();
	}

	cout << q2 << endl;
	cout << endl;
	
	std::cout << std::endl << " --------------------- STAGE_2 (2 Pts) --------------------- " << std::endl;
	
	linkedStack<> s1;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	while (!s1.isEmptyStack())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	s1.pop();
	cout << endl;

	linkedStack<complex<double>> s2;
	s2.push(complex < double>(1, 1));
	s2.push(complex < double>(2, 1));
	s2.push(complex < double>(3, 1));
	s2.push(complex < double>(4, 1));
	while (!s2.isEmptyStack())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
	s2.pop();
	cout << endl;
	
	std::cout << std::endl << " --------------------- STAGE_3 (1,5 Pts) --------------------- " << std::endl;

	// Comment after rpn_value implementation
	
	//string wyrazenie = "This is example of stringstream usage";
	//cout << rpn_value<int>(wyrazenie) << endl;
	//
	// Uncomment after rpn_value implementation
	
	string expression1 = "3 5 2 * +";
	string expression2 = "3 5 + 2 *";
	string expression3 = "6 3 / 2 5 + *";
	string expression4 = "3 6 / 0.25 0.25 + *";

	cout << "3 + 5 * 2  in RPN is:  " << expression1 << " = " << rpn_value<int>(expression1) << endl;
	cout << "(3 + 5) * 2  in RPN is:  " << expression2 << " = " << rpn_value<int>(expression2) << endl;
	cout << "6 / 3 * (2 + 5)  in RPN is:  " << expression3 << " = " << rpn_value<int>(expression3) << endl;
	cout << "3 / 6 * (0.25 + 0.25)  in RPN is:  " << expression4 << " = " << rpn_value<double>(expression4) << endl;
	cout << endl;
	
	std::cout << std::endl << " --------------------- STAGE_4 (1,5 Pts) --------------------- " << std::endl;
	
	cout << rpn("3 + 5 * 2") << " = " << rpn_value<int>(rpn("3 + 5 * 2")) << endl;
	cout << rpn("( 3 + 5 ) * 2") << " = " << rpn_value<int>(rpn("( 3 + 5 ) * 2")) << endl;
	cout << rpn("6 / 3 * ( 2 + 5 )") << " = " << rpn_value<int>(rpn("6 / 3 * ( 2 + 5 )")) << endl;
	cout << rpn("3 / 6 * ( 0.25 + 0.25 )") << " = " << rpn_value<double>(rpn("3 / 6 * ( 0.25 + 0.25 )")) << endl;
	
	return 0;
}