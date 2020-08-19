//Zadanie Pensje XIX OI
//Mateusz Grzelak

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1000001;
int n;

int ojciec[N];
vector<int> synowie[N];
int pensja[N];
bool pensja_jawna[N];

struct Drzewo {
	int rozm; //ilość elementów poddrzewa
	int upp_key; // górny klucz
	int dol_sciezki;
	bool operator<(const Drzewo& d) const { return upp_key < d.upp_key;}
};

int rozmiar_drzewa(int v)
{
	int rozm = 1;
	for (auto it = synowie[v].begin(); it != synowie[v].end(); it++)
		rozm += rozmiar_drzewa(*it);
	return rozm;
}

int dol_sciezki(int v)
{
	if (synowie[v].size() != 1) // drzewo rozgałęzione
		return v;
	else
		return dol_sciezki(synowie[v].front()); // ścieżka - idę po krawędziach ścieżki i zliczam za każdym razem element
}

int main()
{	//Etap I - INPUT
	ios_base::sync_with_stdio(false);
	cin >> n;
	pensja[0] = n + 1; // mozliwe błędy ze wzgledy na pusty indeks 0, numery indeksów odpowiadają numerom pracowników
	for (int i = 1; i <= n; i++)
	{
		cin >> ojciec[i];
		cin >> pensja[i];
		pensja_jawna[pensja[i]] = true;
		if (ojciec[i] == i) // dyrektor
			ojciec[i] = 0;
		synowie[ojciec[i]].push_back(i); // przypisuje synów do odpowiadających ojców
	}
	//Etap II - utworzenie drzewa ukorzenionego
	vector<Drzewo> drzewa;
	for (int i = 1; i <= n; i++)
	{
		if (pensja[i] == 0 && pensja[ojciec[i]] != 0) //warunek utworzenia korzenia poddrzewa - pensja korzenia poddrzewa nie jawna i pensja przełożonego jawna
		{                                            // jeśli korzeń poddrzewa ma pensje nie jawną i jest rozgałęzione to pensja synów nie może być znana więc istotna jest jedynie ich ilość
			Drzewo drzewo;
			drzewo.rozm = rozmiar_drzewa(i);
			drzewo.dol_sciezki = dol_sciezki(i);
			drzewo.upp_key = pensja[ojciec[i]];
			drzewa.push_back(drzewo); // utworzone poddrzewo dodaje do zbioru
		}
	}
	sort(drzewa.begin(), drzewa.end());//sortowanie względem pensji przełożonego korzenia poddrzewa
	//Etap III - Zliczanie pensji
	int sum = 0, last_key=0;
	vector<int> not_used;
	for (auto it = drzewa.begin(); it != drzewa.end(); it++)
	{
		int prev_last = last_key;
		while (last_key < it->upp_key - 1){ //sprawdzam które klucze są nie jawne i dodaje je do kolejki
			++last_key;
			if (!pensja_jawna[last_key])
				not_used.push_back(last_key);
		}

		int v = it->dol_sciezki;
		vector<int> sciezka;
		while (pensja[v] == 0)			// dodaje do kolejki pracowników od dołu, których pensje są nie jawne (od dołu do korzenia ścieżki)
		{
			sciezka.push_back(v);
			v = ojciec[v];
		}

		if (it->rozm == not_used.size() && sum == 0) // całe poddrzewo jest ścieżką więc ze zbioru niewykorzystanych kluczy przypisuje kolejne pracownikom
		{
			while (!sciezka.empty())
			{
				pensja[sciezka.back()] = not_used.back(); // po każdej iteracji czyszczę kolejki i przenosze sie do kolejnego poddrzewa , idąc od lewej do prawej(zgodnie z waruniem kopca)
				sciezka.pop_back();
				not_used.pop_back();

			}
			not_used.clear();
		}
		else                                             
		{
			sum += it->rozm;
			if (sum == not_used.size()) //rozgałęzione poddrzewa, sprawdzam czy jawny przełożony nie ma więcej niż 1 podwladnych 
			{
				while (!sciezka.empty() && not_used.back() > prev_last) 
				{
					pensja[sciezka.back()] = not_used.back();
					not_used.pop_back();
					sciezka.pop_back();
				}
				not_used.clear();
				sum = 0;		
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << pensja[i] << endl;
}
