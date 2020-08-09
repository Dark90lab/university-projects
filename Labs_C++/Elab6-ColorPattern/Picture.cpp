#include "Picture.h"

//---STAGE 1: implement constructors------
//---destructor and necessary operators---
void Picture::init(int size, string*str)
{
		this->height = size;
		this->signs = new string[size];
		for (int i = 0; i < size; i++)
			this->signs[i] = str[i];
}

Picture::Picture(int _h , string* _signs, string _desc)
{
	this->height = _h;
	if(height>0 && _signs!=nullptr)
		this->init(height, _signs);
	else
	{
		this->signs = nullptr;
	}
	this->description = _desc;
}

Picture::~Picture()
{
	if (height > 0 && signs!=nullptr)
	{
		delete[] this->signs;
		height = 0;
		signs = nullptr;
	}

}

Picture::Picture(const Picture& p)
{
	//this->~Picture();
	if (p.height == 0)
		return;
	this->height = p.height;
	this->init(height, p.signs);
	this->description = p.description;
}

Picture& Picture::operator=(const Picture& p)
{
	if (this == &p)
		return *this;
	if (p.height == 0)
		return *this;
	this->height = p.height;
	this->init(height, p.signs);
	this->description = p.description;
	return *this;
}

ostream& operator<<(ostream& out, Picture& p)
{
	out << "Picture: " << p.description << endl << "Size:" << p.getWidth() << "x" << p.getHeight() << endl;
	return out;
}
//----------------------------------------

//---STAGE 2: implement operator[]---

string Picture::operator[](int i) const
{
	//if(i<height)
	return this->signs[i];
}
//-----------------------------------
