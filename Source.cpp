#include "WorkWithFiles.hpp"

#include <iostream>
#include <fstream>

/*
	9. Построить три класса (базовый и 3 потомка), описывающих некоторых хищных
	животных (один из потомков), всеядных(второй потомок) и травоядных (третий
	потомок). Описать в базовом классе абстрактный метод для расчета количества и типа
	пищи, необходимого для пропитания животного в зоопарке.
	a) Упорядочить всю последовательность животных по убыванию количества пищи. При
	совпадении значений – упорядочивать данные по алфавиту по имени. Вывести
	идентификатор животного, имя, тип и количество потребляемой пищи для всех
	элементов списка.
	b) Вывести первые 5 имен животных из полученного в пункте а) списка.
	c) Вывести последние 3 идентификатора животных из полученного в пункте а) списка.
	d) Организовать запись и чтение коллекции в/из файл.
	e) Организовать обработку некорректного формата входного файла.
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
		new Omnivorous{ "Сhimpanzee", 75},
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