#include "io.hpp"

namespace nt
{
	library::library()
	{
		this->module_ = GetModuleHandleA(nullptr);
	}

	PIMAGE_DOS_HEADER library::get_dos_header() const noexcept
	{
		return reinterpret_cast<PIMAGE_DOS_HEADER>(this->get_ptr());
	}

	std::uint8_t* library::get_ptr() const noexcept
	{
		return reinterpret_cast<std::uint8_t*>(this->module_);
	}

	bool library::is_valid() const noexcept
	{
		return this->module_ != nullptr && this->get_dos_header()->e_magic == IMAGE_DOS_SIGNATURE;
	}

	std::string library::get_path() const noexcept
	{
		if (!this->is_valid()) return "";

		char name[MAX_PATH] = { 0 };
		GetModuleFileNameA(this->module_, name, sizeof name);

		return name;
	}

	std::string library::get_folder() const noexcept
	{
		if (!this->is_valid()) return "";

		const auto path = std::filesystem::path(this->get_path());
		return path.parent_path().generic_string();
	}
}