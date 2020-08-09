#include "Library.h"

using namespace std;

// ETAP 4 from
Library::Library()
{
	this->bookCount = 0;
	this->books = nullptr;
}
Library::~Library()
{
	if (this->bookCount > 0)
	{
		bookCount = 0;
		delete[] books;
	}
}
bool Library::AddBook(Book b)
{
	//first case - already 0 books
	if (this->bookCount == 0)
	{
		books = new Book[1];
		books[0] = b;
		bookCount++;
		return true;
	}
	for (int i = 0; i < bookCount; i++)//check for similarity of books
	{
		if (this->books[i] == b)
			return false;
	}
	//resize case
	Book *tmp = new Book[bookCount];
	for (int i = 0; i < bookCount; i++)//copy books 
		tmp[i] = books[i];
	delete[] books;
	books = new Book[bookCount+1];
	for (int i = 0; i < bookCount; i++)
		books[i] = tmp[i];
	books[bookCount] = b;
	bookCount++;
	delete[] tmp;
	return true;

}
std::ostream& operator<<(std::ostream& out, const Library&l)
{
	out << "Prints Library Resources - Count: " << l.bookCount << endl;
	if (l.bookCount > 0)
	{
		for (int i = 0; i < l.bookCount; i++)
			out << l.books[i]<<endl;

		return out;
	}
	else
		out << "Emty library"<<endl;
	return out;
}

// ETAP 4 to