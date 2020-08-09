#include <iostream>
#include "sortedPlaylist.h"
using namespace std;

SortedPlaylist::SortedPlaylist(string _name, SortOrder _order, SortLabel _label) :
	Playlist::Playlist(_name), sortOrder(_order), sortLabel(_label) {}

void SortedPlaylist::sortPlaylist()
{
	songs.sort([&](Song& a, Song& b) 
	{ 
		bool ret;
		if (sortLabel == SortLabel::AUTHOR)
		{
			ret = a.get_author() <= b.get_author();
		}
		else //title
		{
			ret = a.get_title() <= b.get_title();
		}

		return (sortOrder == SortOrder::DESCENDING) ? !ret : ret;
	});
}

void SortedPlaylist::add_song(Song s)
{
	Playlist::add_song(s);
	sortPlaylist();
}

void SortedPlaylist::insert_song_by_genre(list<Song> songList)
{
	Playlist::insert_song_by_genre(songList);
	sortPlaylist();
}

void SortedPlaylist::add_songs(list<Song>& l)
{
	Playlist::add_songs(l);
	sortPlaylist();
}

void SortedPlaylist::add_songs(Playlist& p)
{
	Playlist::add_songs(p);
	sortPlaylist();
}

void SortedPlaylist::set_sort_settings(SortOrder order, SortLabel label)
{
	sortLabel = label;
	sortOrder = order;
	sortPlaylist();
}
