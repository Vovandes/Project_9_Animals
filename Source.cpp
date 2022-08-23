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

int main() {
	std::setlocale(LC_ALL, "");
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	std::string path = "test.txt";

	std::vector<Animals*> vect;

	WorkWithFiles w(path, vect);

	/*vect = {
		new Predators{ "Lion", 201 },
		new Predators{ "Puma", 104 },
		new Omnivorous{ "�himpanzee", 75},
		new Herbivorous{"Giraffe", 250},
		new Predators{ "Tiger", 197 },
		new Herbivorous{"Elephant", 307},
		new Omnivorous{ "Gorilla", 177},
	};*/

	for (const auto& elem : vect) {
		elem->Quantity_and_type_calculation_food();
		std::cout << std::endl;
	}

	vect.push_back(new Omnivorous{ "Bear", 203 });

	w.CopyVect(vect);

	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cout << "Push Enter key..." << std::cin.get();
	return 0;
}