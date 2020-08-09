#include "StudentCard.h"

unsigned short StudentCard:: STUDENT_CARD_COUNT = 0;

/* ----------- STAGE 1 ----------- */
StudentCard::StudentCard()
{
	studentID = STUDENT_CARD_COUNT;
	STUDENT_CARD_COUNT++;
}

StudentCard::StudentCard(StudentCard& studentCard)
{
	this->studentID = studentCard.STUDENT_CARD_COUNT;
	this->validStatus = studentCard.validStatus;
	studentCard.validStatus = CARD_STATUS::INVALID;
	this->bookCount = studentCard.bookCount;
	for (int i = 0; i < bookCount; i++)
		this->studentBooks[i] = studentCard.studentBooks[i];
	STUDENT_CARD_COUNT++;
}

std::ostream& operator<<(std::ostream& out, const StudentCard& studentCard)
{
	out << " " << studentCard.studentID << " ";
	if (studentCard.validStatus == CARD_STATUS::INVALID)
		out << "(Not Valid)" << std::endl;
	else{ out << "(Valid)" << std::endl; }
	if (studentCard.bookCount == 0)
		return out;
	else
	{
		for (int i = 0; i < studentCard.bookCount; i++)
		{
			//if (studentCard.bookCount != 0)
				out << "        " << studentCard.studentBooks[i] << std::endl;
		}
		return out;

	}
}

/* ----------- STAGE 4 ----------- */

unsigned short StudentCard::GetBookCount() const
{
	return this->bookCount;
}

unsigned short StudentCard::GetID() const
{
	return this->studentID;
}