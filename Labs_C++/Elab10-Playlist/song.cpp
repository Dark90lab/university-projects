#include <iostream>
#include "song.h"
using namespace std;

Song::Song(string _author, string _title, Genre _genre, int _length) :
	author(_author), title(_title), genre(_genre), length(_length) {}

bool operator==(const Song& s1, const Song& s2)
{
	return (s1.author == s2.author) && (s1.title == s2.title);
}

ostream& operator<<(ostream& out, const Song& s)
{
	int minutes = s.length / 60;
	int seconds = s.length - minutes * 60;
	string genreStr;

	switch (s.genre)
	{
	case Genre::Pop:
		genreStr = "[Pop]";
		break;
	case Genre::Rock:
		genreStr = "[Rock]";
		break;
	case Genre::Electronic:
		genreStr = "[Electronic]";
		break;
	case Genre::Blues:
		genreStr = "[Blues]";
		break;
	case Genre::Country:
		genreStr = "[Country]";
		break;
	}

	out << s.author << " - " << s.title << " (" << minutes << 
		(seconds < 10 ? ":0" : ":") << seconds << ") " << genreStr << endl;
	return out;
}
