#include "Authors.h"

using namespace std;

// ETAP 1 from
Authors::Authors(std::string* authors, int count)
{
	if (count != 0)
	{
		this->authorsCount = count;
		this->authors = new string[count];
		for (int i = 0; i < count; i++)
			this->authors[i] = authors[i];
	}

}


// ETAP 1 to
Authors::~Authors()
{
	if (this->authorsCount >0)
	{
		delete[] authors;
		authors = nullptr;
		authorsCount = 0;
	}
}

std::ostream& operator<<(std::ostream& out, const Authors& s)
{
	if (s.authorsCount == 0)
	{
		out << "Empty" << endl;
		return out;
	}
	else
	{
		for (int i = 0; i < s.authorsCount; i++)
			out << s.authors[i] << ",";
		return out;

	}
}

// ETAP 2 from
Authors::Authors(const Authors& a)
{

		this->authorsCount = a.authorsCount;
		this->authors = new string[this->authorsCount];
		for (int i = 0; i < this->authorsCount; i++)
			this->authors[i] = a.authors[i];
}

Authors& Authors::operator=(const Authors& a)
{
	if (this == &a)//check if they are equal
		return *this;
	this->~Authors();//clean 
	if (a.authorsCount != 0)
	{
		this->authorsCount = a.authorsCount;
		this->authors = new string[this->authorsCount];
		for (int i = 0; i < this->authorsCount; i++)
			this->authors[i] = a.authors[i];
		return *this;
	}
}


// ETAP 2 to

// ETAP 3 from
bool operator==(const Authors&a, const Authors&b)
{
	if (a.authorsCount != b.authorsCount)
		return false;
	for (int i = 0; i < a.authorsCount; i++)
	{
		if (a.authors[i] != b.authors[i])
			return false;
	}
	return true;
}
bool operator!=(const Authors&a, const Authors&b)
{
	if (a.authorsCount != b.authorsCount)
		return true;
	for (int i = 0; i < a.authorsCount; i++)
	{
		if (a.authors[i] != b.authors[i])
			return true;
	}
	return false;


}


// ETAP 3 to