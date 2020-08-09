#include <iostream>
#include "playlist.h"
using namespace std;

Playlist::Playlist(string _name) :
	name(_name) {}

//could use find but I don't know if students already know about <algorithm> stuff?
void Playlist::add_song(Song s)
{
	for (list<Song>::const_iterator it = songs.begin(); it != songs.end(); it++)
	{
		if (*it == s)
			return;
	}
	songs.push_back(s);
}

void Playlist::add_songs(list<Song>& l)
{
	songs.splice(songs.end(), l);
}

void Playlist::add_songs(Playlist& p)
{
	songs.splice(songs.end(), p.songs);
}

void Playlist::insert_song_by_genre(list<Song> songList)
{
	Song songWithGenre = songList.front();
	for (list<Song>::iterator it = songs.begin(); it != songs.end(); it++)
	{
		if (songWithGenre.get_genre() == it->get_genre())
		{
			songs.insert(it, songWithGenre);
			return;
		}
	}
	songs.push_back(songWithGenre);
}

void Playlist::remove_by_genre(Genre g)
{
	for (list<Song>::iterator it = songs.begin(); it != songs.end();)
	{
		if (it->get_genre() == g)
		{
			it = songs.erase(it);
		}
		else
		{
			it++;
		}		
	}
}

void Playlist::remove_by_author(string a)
{
	songs.remove_if([&](Song& s) { return s.get_author() == a; });
}

void Playlist::remove_by_length(int len)
{
	songs.remove_if(LengthCheck(len));
}

ostream& operator<<(ostream& out, const Playlist& p)
{
	out << "Playlist name: " << p.name << endl;
	if (p.songs.empty())
	{
		out << "There's no songs in this playlist!" << endl;
	}
	else
	{
		for (list<Song>::const_iterator it = p.songs.begin(); it != p.songs.end(); it++)
		{
			out << *it;
		}
	}
	out << endl;
	return out;
}
