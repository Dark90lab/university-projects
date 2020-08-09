#include "Book.h"

using namespace std;


Book::Book(const std::string& _title, Authors _authors, int _publicationYear)
{
	if (_publicationYear != 0)
	{
		this->title = _title;
		this->authors = _authors;
		this->publicationYear = _publicationYear;
	}
}


// ETAP 2 to
std::ostream& operator<<(std::ostream& out, const Book& b)
{
	out << b.title << b.authors << b.publicationYear;
	return out;
}

// ETAP 3 from

bool operator==(const Book& a, const Book& b)
{
	if (a.publicationYear != b.publicationYear || a.title != b.title || a.authors != b.authors)
		return false;

	return true;
}

bool operator!=(const Book& a, const Book& b)
{
	if (a.publicationYear != b.publicationYear || a.title != b.title || a.authors != b.authors)
		return true;

	return false;
}


// ETAP 3 to
