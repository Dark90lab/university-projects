#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class Polynomial: private Array  //add private inheritance
{
protected:

	int degree;

public:

	Polynomial(int _deg=0, int *_coef=nullptr);
	Polynomial(const Polynomial& p);
	Polynomial& operator=(const Polynomial &p);
	~Polynomial() { degree = 0; };

	friend ostream& operator<<(ostream& out, const Polynomial& w);

	//declare and define in Polynomial.cpp
	Polynomial& operator*=(int);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const Polynomial&);

	Polynomial derivtive() const;
	double operator()(double x) const;
};

double poly_root(const Polynomial& w, double x, int& it);