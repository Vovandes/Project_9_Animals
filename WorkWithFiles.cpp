#include "WorkWithFiles.hpp"

WorkWithFiles::WorkWithFiles(const std::string file_name, std::vector<Animals*>& vect)
	: file_name_{ file_name }
{
	ReadFromFile();
	vect = tmp_vect_;
	//tmp_vect_ = vect;
	//std::copy(tmp_vect_.begin(), tmp_vect_.end(), vect);
}

WorkWithFiles::~WorkWithFiles() {
	WriteInFile();
	if (!tmp_vect_.empty()) {
		for (auto elem : tmp_vect_) {
			delete elem;
		}
	}
}

std::string WorkWithFiles::ReadInfo(std::fstream& obj) {
	std::vector<char> buf_;
	std::size_t size_{};
	obj.read(reinterpret_cast<char*>(&size_), sizeof(size_t));
	buf_.resize(size_ + 1);
	obj.read(buf_.data(), size_);
	buf_[size_] = '\0';

	return buf_.data();
}

void WorkWithFiles::ReadFromFile() {

	file_.exceptions(std::ios::badbit | std::ios::failbit);
	file_.open(file_name_, std::ios::binary | std::ios::out | std::ios::in);

	if (!file_.is_open()) {
		throw std::exception("error.not open file.");
	}

	std::size_t sz{};
	file_.read(reinterpret_cast<char*>(&sz), sizeof(std::size_t));
	if (!file_.eof()) {
		//tmp_vect_.resize(sz);

		for (std::size_t i = 0; i < sz; ++i) {
			// id_:
			std::size_t tmp_id_{};
			file_.read(reinterpret_cast<char*>(&tmp_id_), sizeof(std::size_t));

			// name_:
			auto tmp_name_ = ReadInfo(file_);

			// type_food_:
			auto tmp_tf_{ Animals::TypeFood::None };
			file_.read(reinterpret_cast<char*>(&tmp_tf_), sizeof(Animals::TypeFood));

			// amount_food_:
			std::size_t tmp_amount_food_{};
			file_.read(reinterpret_cast<char*>(&tmp_amount_food_), sizeof(std::size_t));

			Animals* tmp{ nullptr };
			switch (tmp_tf_) {
			case Animals::TypeFood::Meat:
				tmp = new Predators{ tmp_name_, tmp_amount_food_ };
				break;
			case Animals::TypeFood::Grass:
				tmp = new Herbivorous{ tmp_name_, tmp_amount_food_ };
				break;
			case Animals::TypeFood::All:
				tmp = new Omnivorous{ tmp_name_, tmp_amount_food_ };
				break;
			default:
				break;
			}
			tmp->setID(tmp_id_);
			//tmp_vect_[i] = tmp;
			tmp_vect_.push_back(tmp);
			//delete tmp;
		}
	}
	file_.close();
}

void WorkWithFiles::WriteInFile() {

	file_.exceptions(std::ios::badbit | std::ios::failbit);
	file_.open(file_name_, std::ios::binary | std::ios::out | std::ios::in);

	if (!file_.is_open()) {
		throw std::exception("error.not open file.");
	}

	std::size_t sz = tmp_vect_.size();
	file_.write(reinterpret_cast<char*>(&sz), sizeof(std::size_t));

	for (const auto elem : tmp_vect_) {
		// id_:
		auto temp_id_ = elem->getID();
		file_.write(reinterpret_cast<char*>(&temp_id_), sizeof(std::size_t));

		// name_:
		std::size_t size_ = elem->getNameAnimal().size();
		file_.write(reinterpret_cast<char*>(&size_), sizeof(std::size_t));
		file_.write(elem->getNameAnimal().data(), size_);

		// type_food_:
		auto tmp_tf = elem->getTypeFood();
		file_.write(reinterpret_cast<char*>(&tmp_tf), sizeof(Animals::TypeFood));

		// amount_food_:
		auto tmp_ = elem->getAmountFood();
		file_.write(reinterpret_cast<char*>(&tmp_), sizeof(std::size_t));
	}
	file_.close();
}