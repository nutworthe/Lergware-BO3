#pragma once
#include "../includes.h"
using json = nlohmann::json;

namespace io
{
	std::string get_json_file(const std::string & name);
	std::ifstream read_json_file(const std::string & name);
	json parse_json_file(const std::string& name);
	bool write_file(const std::string & file, const std::string & data);
	bool create_directory(const std::string & directory);
	bool file_exists(const std::string & file);
}