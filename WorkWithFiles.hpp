#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <algorithm>

#include "Animals.hpp"

class WorkWithFiles {
public:
	WorkWithFiles(const std::string file_name, std::vector<Animals*>& vect);
	WorkWithFiles(const WorkWithFiles&) = delete;
	WorkWithFiles(WorkWithFiles&&) = delete;
	WorkWithFiles& operator =(const WorkWithFiles&) = delete;
	WorkWithFiles& operator =(WorkWithFiles&&) = delete;
	~WorkWithFiles();

	void CopyVect(const std::vector<Animals*>& vect) {
		//auto tmp{ vect };
		tmp_vect_ = vect;
		//std::copy(vect.begin(), vect.end(), tmp_vect_);
	}

private:
	const std::string file_name_;
	std::fstream file_;
	std::vector<Animals*> tmp_vect_;

	Animals* ParsingCSV_String(const std::string& pars_str);

	void ReadFromFile();
	void WriteInFile();
	bool is_empty(std::fstream& pfile_) { return pfile_.peek() == std::fstream::traits_type::eof(); }
};