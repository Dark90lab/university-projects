#pragma once
using namespace std;


class Food
{
public:
	static const int TYPE_COUNT = 2;
	virtual ~Food() = default;
	virtual Food* clone() const = 0;
};

//---PART 0 - implement here
//---Create Grain and Fish classes

class Grain : public Food
{
	float amount;
public:
	Grain(float _amount) : amount(_amount) {}
	float GetAmount() { return amount; };
	void EatFood(float howMuch) { amount -= howMuch; };
	virtual Grain* clone() const { return new Grain(*this); };
};

class Fish : public Food
{
	int amount;
public:
	Fish(int _amount) : amount(_amount) {}
	int GetAmount() { return amount; };
	void EatFood(int howMuch) { amount -= howMuch; };
	virtual Fish* clone() const { return new Fish(*this); };
};