#include "WorkWithFiles.hpp"

#include <sstream>

WorkWithFiles::WorkWithFiles(const std::string file_name, std::vector<Animals*>& vect)
	: file_name_{ file_name }
{
	ReadFromFile();
	vect = tmp_vect_;
}

WorkWithFiles::~WorkWithFiles() {
	WriteInFile();
	if (!tmp_vect_.empty()) {
		for (auto elem : tmp_vect_) {
			delete elem;
		}
	}
}

Animals* WorkWithFiles::ParsingCSV_String(const std::string& pars_str) {
	std::size_t tmp_id{};
	std::string tmp_name;
	Animals::TypeFood tmp_type_food{ Animals::TypeFood::None };
	std::size_t tmp_amount_food{};

	std::istringstream buffer{ pars_str };
	std::string buffer_str;

	std::getline(buffer, buffer_str, ';');
	tmp_id = static_cast<std::size_t>(std::stoi(buffer_str));

	std::getline(buffer, buffer_str, ';');
	tmp_name = buffer_str;

	std::getline(buffer, buffer_str, ';');
	if (buffer_str == "Predators") {
		tmp_type_food = Animals::TypeFood::Meat;
	}
	else if (buffer_str == "Herbivorous") {
		tmp_type_food = Animals::TypeFood::Grass;
	}
	else if (buffer_str == "Omnivorous") {
		tmp_type_food = Animals::TypeFood::All;
	}
	else {
		throw std::exception("Error! Incorect Data!");
	}

	std::getline(buffer, buffer_str, ';');
	tmp_amount_food = static_cast<std::size_t>(std::stoi(buffer_str));

	Animals* tmp{};

	switch (tmp_type_food) {
	case Animals::TypeFood::Meat:
		tmp = new Predators{ tmp_name, tmp_amount_food };
		break;
	case Animals::TypeFood::Grass:
		tmp = new Herbivorous{ tmp_name, tmp_amount_food };
		break;
	case Animals::TypeFood::All:
		tmp = new Omnivorous{ tmp_name, tmp_amount_food };
		break;
	default:
		break;
	}
	tmp->setID(tmp_id);

	return tmp;
}

void WorkWithFiles::ReadFromFile() {
	file_.open(file_name_, std::ios::binary | std::ios::out | std::ios::in | std::ios::app);
	file_.exceptions(std::ios::badbit);

	if (!file_.is_open()) {
		throw std::exception("Cannot open file!");
	}

	std::string line;

	while (std::getline(file_, line)) {
		tmp_vect_.push_back(ParsingCSV_String(line));
	}

	file_.close();
}

void WorkWithFiles::WriteInFile() {
	file_.exceptions(std::ios::badbit);
	file_.open(file_name_, std::ios::binary | std::ios::out | std::ios::in);

	if (!file_.is_open()) {
		throw std::exception("Cannot open file !");
	}

	for (const Animals* animal : tmp_vect_) {
		file_ << *animal << std::endl;
	}

	file_.close();
}