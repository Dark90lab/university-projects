#include "ColorPatternBrush.h"

//---STAGE 4: implement constructor-------

ColorPatternBrush::ColorPatternBrush(string _name, short _color, short _altColor,int _clrLen, int _altClrLen, Picture _pic):ColorBrush(_name,color,_pic)
{
	this->alternateColor = _altColor;
	this->alternateColorLength = _altClrLen;
	this->colorLength = _clrLen;
}


//---getAlternateColor and paint methods--
short ColorPatternBrush::getAlternateColor() const { return this->alternateColor; }

void  ColorPatternBrush::paint()
{
	int count = 0;
	int sumLen = colorLength + alternateColorLength;
	for (int i = 0; i < (*this).Brush::picture.getHeight(); i++)
	{
		for (int j = 0; j < (*this).Brush::picture.getWidth(); j++)
		{
			if (count >= colorLength && count < sumLen)
				useColor(alternateColor);
			else if (count < colorLength)
				useColor(color);
			else
			{
				useColor(color);
				count = 0;
			}
			count++;
			cout << (*this).picture[i][j];
			resetColor();
		}
		cout << endl;
	}
}
//----------------------------------------
