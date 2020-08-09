#include "petShop.h"

//---PART 3 - implement here
//---constructor, destructor, Add Pet
//---Feed pets and operator<<

PetShop::PetShop(Food* food[2]) : foodAmount(nullptr)
{
	petCount = 0;
	foodAmount = new Food*[2];
	for (int i = 0; i < 2; i++)
		foodAmount[i] = food[i]->clone();
}

PetShop::~PetShop()
{
	for (int i = 0; i < petCount; i++)
		delete pets[i];
	for (int i = 0; i < 2; i++)
		delete foodAmount[i];
	delete[] foodAmount;
}

void PetShop::AddPet(Pet* pet)
{
	if (petCount < MAX_PET_COUNT) {
		pets[petCount] = pet;
		petCount++;
	}
}

ostream& operator<<(ostream& out, const PetShop& shop)
{
	out << "Pet shop with " << shop.petCount << " animals" << endl;
	out <<"Amount of food:" << endl;
	Fish* fish;
	if (fish = dynamic_cast<Fish*>(shop.foodAmount[0]));
	else (fish = dynamic_cast<Fish*>(shop.foodAmount[1]));
	Grain* gr;
	if (gr = dynamic_cast<Grain*>(shop.foodAmount[0]));
	else (gr = dynamic_cast<Grain*>(shop.foodAmount[1]));
	out << "Grain: " << gr->GetAmount() << " Fish: " << fish->GetAmount() << endl << endl;
	for (int i = 0; i < shop.petCount; i++)
		out << *(shop.pets[i]) << endl;
	return out;
}

void PetShop::FeedPets()
{
	for (int i = 0; i < petCount; i++)
		if(!pets[i]->IsSick())
			pets[i]->Feed(foodAmount);;
}

//---PART 4 - implement here
//---feeding pelicans after others

void PetShop::FeedPelicansLast()
{
	for (int i = 0; i < petCount; i++) {
		if (!pets[i]->IsSick()) {
			Pelican* pelican = dynamic_cast<Pelican*> (pets[i]);
			if (pelican == nullptr)
				pets[i]->Feed(foodAmount);
		}
	}
	for (int i = 0; i < petCount; i++) {
		if (!pets[i]->IsSick()) {
			Pelican* pelican = dynamic_cast<Pelican*> (pets[i]);
			if (pelican != nullptr)
				pets[i]->Feed(foodAmount);
		}
	}
}

//---PART 5 - implement here
//---Curing cats by removing hamsters

void PetShop::CureCats()
{
	int lastPetCount = petCount;
	for (int i = 0; i < petCount; i++) {
		if (pets[i]->IsSick()) {
			Cat* cat = dynamic_cast<Cat*>(pets[i]);
			if (cat != nullptr) {
				for (int j = 0; j < petCount; j++) {
					Hamster* hamster = dynamic_cast<Hamster*>(pets[j]);
					if (hamster != nullptr) {
						pets[i]->Cure();
						RemovePet(j);
						i = 0;
						break;
					}
				}
			}
		}
	}
}

void PetShop::RemovePet(int index)
{
	delete pets[index];
	pets[index] = pets[petCount - 1];
	petCount--;
}

