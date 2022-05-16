#pragma once
#include "../includes.h"

#define FRIENDS_LIST "friends.json"

namespace utils
{
	template <typename T>
	static auto atoi(const std::string& str)
	{
		return static_cast<T>(std::atoi(str.data()));
	}
	
	static auto atoi(const std::string& str)
	{
		return atoi<std::uint32_t>(str);
	}

	static auto atoll(const std::string& str)
	{
		return static_cast<std::uint64_t>(std::atoll(str.data()));
	}
}