#include "Library.h"

/* ----------- STAGE 2 ----------- */

Library::Library(Book books[MAX_LIBRARY_BOOKS], unsigned short counts[MAX_LIBRARY_BOOKS])
{
	
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
	{
		resources[i].book = books[i];
		resources[i].count = counts[i];
	}

}

std::ostream& operator<<(std::ostream& out, Library& library)
{
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
	{
		out <<"Book No: "<< "(" << library.resources[i].count << ") " << library.resources[i].book << std::endl;
	}

	return out;
}


/* ----------- STAGE 3 ----------- */

void Library::AddStudent(Student& newStudent)
{
	if (Library::STUDENTS_COUNT >= MAX_STUDENTS)
		return;
	this->students[STUDENTS_COUNT]= newStudent.GetID();
	newStudent.ValidateStudentCard();
	STUDENTS_COUNT++;

}

/* ----------- STAGE 4 ----------- */
void MakeReservation(Library& library, Student& student, unsigned short bookID, unsigned short amount)
{
	bool test = false;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (student.GetID() == library.students[i] && student.studentCard.Status() == CARD_STATUS::VALID)
			test = true;
	}
	if (test == false)
		return;
	for (int i = 0; i < MAX_LIBRARY_BOOKS; i++)
	{
		if (library.resources[i].book.GetBookID() == bookID) //i find proper book
		{
			if (library.resources[i].count > 0 && student.studentCard.GetBookCount() < MAX_STUDENT_BOOKS)//more than 0 available book and student has less then MAX
			{
				if(amount >= library.resources[i].count)
				{
					for (int j = 0; j < library.resources[i].count; j++)
						student.BorrowBook(library.resources[i].book);
					library.resources[i].count = 0;
				}
				else
				{
					for (int j = 0; j < amount; j++)
					{
						student.BorrowBook(library.resources[i].book);
						library.resources[i].count--;
					}
				}
			}
		}
	}
}