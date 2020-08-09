#include "Array.h"

void Array::init(int _size, int* _coef) {
	//fill missing code
	if (_size > 0 && _coef!=nullptr)
	{
		size = _size;
		this->tab = new int[_size];
		for (int i = 0; i < size; i++)
			tab[i] = _coef[i];
	}
	else if(_size>0 && _coef==nullptr)
	{
		size = _size;
		tab = new int[size];
		for (int i = 0; i < size; i++)
			tab[i] = 0;
	}
	else
	{
		size = 0;
		tab = nullptr;
	}
}


//fill missing constructors, destructor, operator= (if needed)
Array::Array(int _size, int* _coef)
{
	this->init(_size, _coef);
}

Array::~Array()
{
	if (size > 0)
	{
		delete[] this->tab;
		size = 0;
		tab = nullptr;
	}
}

Array::Array(const Array& a)
{
		this->~Array();
		if (a.size == 0)
			return;
		this->init(a.size, a.tab);
}

Array& Array::operator=(const Array& a)
{
	if (this == &a)
		return *this;
	this->~Array();
	if (a.size == 0)
		return *this;
	this->init(a.size, a.tab);
	return *this;
}

//fill missing operator+ operator- operator*
Array& Array::operator*=(int val)
{
	if (!tab)
		return *this;
	for (int i = 0; i < size; i++)
		tab[i] *= val;
	return *this;
}

Array operator+(const Array&a1, const Array&a2)
{
	Array result;
	if (a1.size != a2.size)
		return result;
	result.init(a1.size,a1.tab);
	for (int i = 0; i < a1.size; i++)
		result.tab[i] =result.tab[i]+ a2.tab[i];
	return result;
}

Array operator-(Array&a1, Array&a2)
{
	Array result;
	if (a1.size != a2.size || (a1.size == a2.size == 0))
		return result;
	result.init(a1.size, a1.tab);
	for (int i = 0; i < a1.size; i++)
		result.tab[i] -= a2.tab[i];
	return result;
}


ostream& operator<<(ostream& out, Array& a)
{
	if (a.size < 1) out << "Empty Array";

	for (int i = 0; i < a.size; i++)
		out << showpos << *(a.tab + i) << "  ";
	return out;
}
