#include "Brush.h"

//---STAGE 2: implement constructor--

Brush::Brush(string _name, Picture _pic): name(_name),picture(_pic){}

//---operator<< and paint method-----
ostream& operator<<(ostream& out, Brush& b)
{
	out << "Brush: " << b.name << endl << b.picture;
	return out;

}

void Brush::paint()
{
	for (int i = 0; i < this->picture.getHeight(); i++)
		cout << this->picture[i] << endl;
}
//-----------------------------------
//---STAGE 4: implement setPicture---
void Brush::setPicture(Picture p)
{
	this->picture = p;
}
//-----------------------------------