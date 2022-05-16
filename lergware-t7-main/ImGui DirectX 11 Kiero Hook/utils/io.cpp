#include "io.hpp"

namespace io
{
	bool write_file(const std::string& file, const std::string& data)
	{
		if (const auto pos = file.find_last_of("/\\"); pos != std::string::npos)
		{
			create_directory(file.substr(0, pos));
		}

		std::ofstream stream(file, std::ios::binary | std::ofstream::out);

		if (stream.is_open())
		{
			stream.write(data.data(), data.size());
			stream.close();

			return true;
		}

		return false;
	}
	
	bool create_directory(const std::string& directory)
	{
		return std::filesystem::create_directories(directory);
	}
	
	bool file_exists(const std::string& file)
	{
		return std::ifstream(file).good();
	}

	std::string get_json_file(const std::string& name)
	{
		const nt::library self;
		return self.get_folder() + "\\lergware\\json\\" + name;
	}

	std::ifstream read_json_file(const std::string& name)
	{
		if (const auto file = get_json_file(name); file_exists(file))
		{
			return std::ifstream(file);
		}

		return {};
	}

	json parse_json_file(const std::string& name)
	{
		auto json_file = read_json_file(name);
		return json::parse(json_file);
	}
}