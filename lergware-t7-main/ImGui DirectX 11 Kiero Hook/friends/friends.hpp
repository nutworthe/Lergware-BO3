#pragma once
#include "../includes.h"

namespace friends
{
	struct friends_t
	{
		std::uint64_t steam_id;
		std::string name;
		netadr_t netadr;
	}; 

	void refresh_friends();
	void friends_list();

	extern std::vector<friends_t> friends;
}