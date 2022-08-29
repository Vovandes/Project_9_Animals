#include "WorkWithFiles.hpp"

#include <iostream>
#include <fstream>

/*
	9. ��������� ��� ������ (������� � 3 �������), ����������� ��������� ������
	�������� (���� �� ��������), ��������(������ �������) � ���������� (������
	�������). ������� � ������� ������ ����������� ����� ��� ������� ���������� � ����
	����, ������������ ��� ���������� ��������� � ��������.
	a) ����������� ��� ������������������ �������� �� �������� ���������� ����. ���
	���������� �������� � ������������� ������ �� �������� �� �����. �������
	������������� ���������, ���, ��� � ���������� ������������ ���� ��� ����
	��������� ������.
	b) ������� ������ 5 ���� �������� �� ����������� � ������ �) ������.
	c) ������� ��������� 3 �������������� �������� �� ����������� � ������ �) ������.
	d) ������������ ������ � ������ ��������� �/�� ����.
	e) ������������ ��������� ������������� ������� �������� �����.
*/

#include <cstdio>
//#include <fmt/core.h>
//#include <fmt/os.h>

void SpecialPrintName(std::vector<Animals*> obj, std::size_t count) noexcept;
void SpecialPrintID(std::vector<Animals*> obj, std::size_t count) noexcept;

int main() {
	std::setlocale(LC_ALL, "");
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	try {

		std::string path = "test.csv";

		std::vector<Animals*> vect;

		WorkWithFiles wW(path, vect);

		/*vect = {
			new Predators{ "Lion", 201 },
			new Predators{ "Puma", 104 },
			new Omnivorous{ "�himpanzee", 75},
			new Herbivorous{"Giraffe", 250},
			new Predators{ "Tiger", 197 },
			new Herbivorous{"Elephant", 307},
			new Omnivorous{ "Gorilla", 177},
		};*/

		auto lmd = [](Animals* a, Animals* b) -> bool {
			if (a->getAmountFood() == b->getAmountFood()) {
				return a->getNameAnimal() < b->getNameAnimal();
			}
			return a->getAmountFood() < b->getAmountFood();
		};

		std::sort(vect.begin(), vect.end(), lmd);

		for (const auto elem : vect) {
			elem->Quantity_and_type_calculation_food();
			std::cout << std::endl;
		}

		SpecialPrintName(vect, 5);
		SpecialPrintID(vect, 3);

		//vect.push_back(new Herbivorous{ "Cow", 177 });
		//vect.push_back(new Omnivorous{ "Bear", 203 });

		wW.CopyVect(vect);
	}
	catch (std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "Push Enter key..." << std::cin.get();
	return 0;
}

void SpecialPrintName(std::vector<Animals*> obj, std::size_t count) noexcept {
	if (obj.empty()) {
		return;
	}
	std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
	for (std::size_t i = 0; i < count; ++i) {
		std::cout << obj[i]->getNameAnimal() << std::endl;
	}
	std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
}

void SpecialPrintID(std::vector<Animals*> obj, std::size_t count) noexcept {
	if (obj.empty()) {
		return;
	}
	std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
	for (auto it = obj.rbegin(), itr = obj.rbegin() + count; it != itr; ++it) {
		std::cout << (*it)->getID() << std::endl;
	}
	std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
}