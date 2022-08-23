#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class Animals {
public:
	//---------------------------------------------------------------------------------------------------------------
	enum class TypeFood : std::size_t {
		None = 0,
		Meat,		// ����
		Grass,		// �����
		All,		// ��������
	} type_food_;
	//---------------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------
	Animals(std::size_t id = ReturnRandom());
	Animals(const Animals& rhs);
	virtual ~Animals() {};
	//---------------------------------------------------------------------------------------------------------------
	std::size_t getID() const { return id_; }
	void setID(std::size_t id) { id_ = id; }
	TypeFood getTypeFood() const { return type_food_; }
	void setTypeFood(TypeFood tf) { type_food_ = tf; }
	std::size_t getAmountFood() const { return amount_food_; }
	void setAmountFood(std::size_t am) { amount_food_ = am; }
	const std::string& getNameAnimal() const { return name_; }
	void setNameAnimal(std::string name) { name_ = name; }
	//---------------------------------------------------------------------------------------------------------------
	virtual void Quantity_and_type_calculation_food() = 0;
private:
	std::size_t id_;
	//TypeFood type_food_;
	std::size_t amount_food_;
	std::string name_;
	static std::vector<std::size_t> vect_id_;

	static std::size_t ReturnRandom() {
		std::size_t tmp = std::rand() % 1001;
		return tmp;
	}

	friend std::ostream& operator << (std::ostream& uout, const Animals& rhs);

	friend std::istream& operator >> (std::istream& uin, Animals& rhs);
};

inline std::vector<std::size_t> Animals::vect_id_;

/*
	9. ��������� ��� ������ (������� � 3 �������), ����������� ��������� ������
	�������� (���� �� ��������), ��������(������ �������) � ���������� (������
	�������). ������� � ������� ������ ����������� ����� ��� ������� ���������� � ����
	����, ������������ ��� ���������� ��������� � ��������.

	a)	����������� ��� ������������������ �������� �� �������� ���������� ����. ���
		���������� �������� � ������������� ������ �� �������� �� �����. �������
		������������� ���������, ���, ��� � ���������� ������������ ���� ��� ����
		��������� ������.

	b)	������� ������ 5 ���� �������� �� ����������� � ������ �) ������.

	c)	������� ��������� 3 �������������� �������� �� ����������� � ������ �) ������.

	d)	������������ ������ � ������ ��������� �/�� ����.

	e)	������������ ��������� ������������� ������� �������� �����.
*/

class Predators : public Animals {
public:
	explicit Predators(std::string name, std::size_t amount);
	void Quantity_and_type_calculation_food() override;
private:
};

class Herbivorous : public Animals {
public:
	explicit Herbivorous(std::string name, std::size_t amount);
	void Quantity_and_type_calculation_food() override;
private:
};

class Omnivorous : public Animals {
public:
	explicit Omnivorous(std::string name, std::size_t amount);
	void Quantity_and_type_calculation_food() override;
private:
};