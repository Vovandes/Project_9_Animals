#include "Animals.hpp"

Animals::Animals(std::size_t id)
	: id_{ id }
	, type_food_{ TypeFood::None }
	, amount_food_{ 0 } {

	for (bool b = true; b != false;) {
		auto x = std::find(vect_id_.begin(), vect_id_.end(), id_);
		vect_id_.empty() ?
			b = false :
			x != vect_id_.end() ? id_ = ReturnRandom() : b = false;
	}
	vect_id_.emplace_back(id_);
}

Animals::Animals(const Animals& rhs)
: id_ {rhs.id_}
, name_ {rhs.name_}
, type_food_ {rhs.type_food_}
, amount_food_ {rhs.amount_food_} {}

Predators::Predators(std::string name, std::size_t amount) : Animals() {
	setTypeFood(Animals::TypeFood::Meat);
	setNameAnimal(name);
	setAmountFood(amount);
}

void Predators::Quantity_and_type_calculation_food() {
	std::cout
		<< "ID Animal is " << getID() << std::endl
		<< "Name Animal is " << getNameAnimal() << std::endl
		<< "Type Food is Meat" << std::endl
		<< "Amount Food is " << getAmountFood() << std::endl;
}

Herbivorous::Herbivorous(std::string name, std::size_t amount) : Animals() {
	setTypeFood(Animals::TypeFood::Grass);
	setNameAnimal(name);
	setAmountFood(amount);
}

void Herbivorous::Quantity_and_type_calculation_food() {
	std::cout
		<< "ID Animal is " << getID() << std::endl
		<< "Name Animal is " << getNameAnimal() << std::endl
		<< "Type Food is Grass" << std::endl
		<< "Amount Food is " << getAmountFood() << std::endl;
}

Omnivorous::Omnivorous(std::string name, std::size_t amount) : Animals() {
	setTypeFood(Animals::TypeFood::All);
	setNameAnimal(name);
	setAmountFood(amount);
}

void Omnivorous::Quantity_and_type_calculation_food() {
	std::cout
		<< "ID Animal is " << getID() << std::endl
		<< "Name Animal is " << getNameAnimal() << std::endl
		<< "Type Food is All" << std::endl
		<< "Amount Food is " << getAmountFood() << std::endl;
}

std::ostream& operator<<(std::ostream& uout, const Animals& rhs) {
	//uout << rhs->id_ << " " << rhs->name_ << " " << static_cast<std::size_t>(rhs->type_food_) << " " << rhs->amount_food_;
	uout << rhs.id_ << " " << rhs.name_ << " " << static_cast<std::size_t>(rhs.type_food_) << " " << rhs.amount_food_;
	return uout;
}

//std::ostream& operator<<(std::ostream& uout, const Animals::TypeFood& rhs) {
//	// TODO: вставьте здесь оператор return   
//}	tmp >>	rhs.type_food_ = static_cast<Animals::TypeFood>(tmp);		std::size_t tmp;


std::istream& operator>>(std::istream& uin, Animals& rhs) {
	std::size_t tmp_;
	uin >> rhs.id_ >> rhs.name_ >> tmp_ >> rhs.amount_food_;
	rhs.type_food_ = static_cast<Animals::TypeFood>(tmp_);
	return uin;
}

//std::istream& operator>>(std::istream& uin, Animals::TypeFood& rhs) {
//	// TODO: вставьте здесь оператор return
//}
