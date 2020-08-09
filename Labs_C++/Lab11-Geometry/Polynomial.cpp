#include "Polynomial.h"
#include <cmath>

//define missing constructor(s)

Polynomial::Polynomial(int _deg , int* _coef)
{
	if (_deg > 0 && _coef == nullptr)
	{
		this->degree = -1;
		return;
	}
	this->degree = _deg;
	this->size = degree + 1;
	this->init(size, _coef);

}

//Polynomial::~Polynomial()
//{
//	this->degree = 0;
//}


ostream& operator<<(ostream& out, const Polynomial& w)
{
	//fill missing code
	if (w.degree == 0)
		out << "Empty polynomial";
	else if (w.degree == -1)
	{
		out << " ";
	}
	else
	{	
		int k = w.degree;
		for (int j = w.size - 1; j >=0;j--,k--)
		{
			if (j > 0 && k>0)
			{
					out << showpos << w.tab[j] << "x^" << noshowpos << k;
			}
			else
			{
				if(w.tab[j]!=0)
					out << showpos << w.tab[j];
			}
		}
	}
	return out;
}

Polynomial::Polynomial(const Polynomial& p)
{
	//(*this).Array::operator=(p);
	this->~Polynomial();
	if (p.degree > 0)
		this->degree = p.degree;
		this->init(p.size, p.tab);
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	if (this == &p)
		return *this;
	this->~Polynomial();
	if (p.degree > 0)
		this->degree = p.degree;
	this->init(p.size, p.tab);
	return *this;

}

Polynomial& Polynomial::operator*=(int val)
{
	if (!tab)
		return *this;
	for (int i = 0; i < size; i++)
		tab[i] *= val;
	return *this;
}

Polynomial operator+(const Polynomial&p1, const Polynomial&p2)
{
	Polynomial result;
	if (p1.size != p2.size)
		return result;
	result.degree = p1.degree;
	result.init(p1.size, p1.tab);
	for (int i = 0; i < p1.size; i++)
		result.tab[i] += p2.tab[i];
	return result;
}
Polynomial operator-(const Polynomial&p1, const Polynomial&p2)
{
	if (p2.degree<0)
		return p1;
	Polynomial result;
	if (p1.size != p2.size)
		return result;
	result.degree = p1.degree;
	result.init(p1.size, p1.tab);
	for (int i = 0; i < p1.size; i++)
		result.tab[i] = result.tab[i]- p2.tab[i];
	return result;
	

}

Polynomial Polynomial::derivtive() const 
{
	//add missing code
	Polynomial tmp=*this;
	int count = degree;
	for (int i = count; i >=0; i--)
	{
		tmp.tab[i] *= count;
		count--;
	}
	tmp.degree = this->degree - 1;
	return tmp;
}


double Polynomial::operator()(double x) const
{
	/*cout << "Degree: " << degree <<" Szie: "<<size<<" ";
	for (int i = 0; i < size; i++)
		cout << tab[i] << " ";*/
	double result = tab[size-1]*x+tab[size-2];
	if (degree > 1)
	{
		for (int i = size - 3; i >= 0; i--)
			result = result * x + tab[i];
	}
	return result;
}

double poly_root(const Polynomial& w, double x, int& it)
{
	double eps = 1e-3;    // epsilon value
	int max_it = 100;	  // maximum iteration count
	
	for (it = 0; it < max_it; it++)	// actual number of iterations 
	{
		//implement Newton's method
		Polynomial tmp = w.derivtive();
		double prev = x;
		x-=(w(x)/tmp(x));
		if (abs(x - prev) < eps || abs(tmp(x)) < eps)
			return x;
		tmp.~Polynomial();	
	}

	cout << "not convergent" << endl;
	return x;
}
