#pragma once
#include "../includes.h"

#include <iostream>
#include <filesystem>

namespace nt
{
	class library final
	{
	public:
		library();

		bool is_valid() const noexcept;
		std::string get_path() const noexcept;
		std::string get_folder() const noexcept;
		std::uint8_t* get_ptr() const noexcept;
		
		PIMAGE_DOS_HEADER get_dos_header() const noexcept;

	private:
		HMODULE module_;
	};
}