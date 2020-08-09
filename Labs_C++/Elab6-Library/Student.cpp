#include "Student.h"

/* ----------- STAGE 3 ----------- */
Student::Student(const char _surname[MAX_CHAR], const char _name[MAX_CHAR])
{
	strcpy(this->surname, _surname);
	strcpy(this->name, _name);
	studentCard;

}

void Student::ValidateStudentCard()
{
	studentCard.SetState(CARD_STATUS::VALID);
}

unsigned short Student::GetID() const
{
	return studentCard.studentID;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
	out << student.surname << " " << student.name << " " << student.studentCard;
	return out;

}

/* ----------- STAGE 4 ----------- */
void Student::BorrowBook(Book newBook)
{
	this->studentCard.studentBooks[studentCard.bookCount] = newBook;
	studentCard.bookCount++;
}

/* ----------- STAGE 5 ----------- */

void Student::LostStudentCard()
{
	if (this->studentCard.Status() != CARD_STATUS::VALID)
		return;
	StudentCard tmp(this->studentCard);
	studentCard = tmp;


}