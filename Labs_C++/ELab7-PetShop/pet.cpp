#include "pet.h"

//---PART 1 - implement here
//---abstract pet class and hamster

Pet::Pet(string _name, int _weight)
{
	name = _name;
	weight = _weight;
}

ostream& operator<<(ostream& out, const Pet& pet)
{
	out << pet.name << endl;
	pet.Print(out);
	out << "Weight: " << pet.weight << endl;
	out << pet.name << (pet.isSick ? " is Sick" : " is healthy") << endl;
	return out;
}

Hamster::Hamster(string _name, int _weight, float _hungerGrain) :
	Pet(_name, _weight)
{
	hungerGrain = _hungerGrain;
}

void Hamster::Feed(Food* food[2])
{
	if (!isSick) {
		Grain* gr;
		if (gr = dynamic_cast<Grain*>(food[0]));
		else (gr = dynamic_cast<Grain*>(food[1]));
		if (gr->GetAmount() > hungerGrain) {
			gr->EatFood(hungerGrain);
		}
		else {
			isSick = true;
		}
	}
}

void Hamster::Print(ostream& out) const
{
	out << "Hamster" << std::endl;
	out << "Eats " << hungerGrain << " of grain" << endl;
}

//---PART 2 - implement here
//---pelican and cat class

Pelican::Pelican(string _name, int _weight, float _hungerGrain, int _hungerFish) :
	Pet(_name, _weight)
{
	hungerGrain = _hungerGrain;
	hungerFish = _hungerFish;
}

void Pelican::Feed(Food* food[2])
{
	if (!isSick) {
		Fish* fish;
		if (fish = dynamic_cast<Fish*>(food[0]));
		else (fish = dynamic_cast<Fish*>(food[1]));
		Grain* gr;
		if (gr = dynamic_cast<Grain*>(food[0]));
		else (gr = dynamic_cast<Grain*>(food[1]));
		float wantGrain = weight * hungerGrain;
		if(gr->GetAmount()>wantGrain && fish->GetAmount() > hungerFish) {
			gr->EatFood(wantGrain);
			fish->EatFood(hungerFish);
		}
		else
			isSick = true;		
	}


}

void Pelican::Print(ostream& out) const
{
	out << "Pelican" << endl;
	out << "Eats a " << hungerGrain << " of his weight of grain and ";
	out << hungerFish << " fish" << endl;
}

Cat::Cat(string _name, int _weight, int _hunger) :
	Pet(_name, _weight)
{
	hunger = _hunger;
}

void Cat::Feed(Food* food[2])
{
	if (!isSick) {
		Fish* fish;
		if (fish = dynamic_cast<Fish*>(food[0]));
		else (fish = dynamic_cast<Fish*>(food[1]));
		if (fish->GetAmount() >= hunger) {
			fish->EatFood(hunger);
		}
		else
			isSick = true;
	}
}

void Cat::Print(ostream& out) const
{
	out << "Cat eating " << hunger << " fish" << endl;
}

