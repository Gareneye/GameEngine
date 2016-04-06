#pragma once

#include <string>
#include <map>
#include "Logger.h"

class Settings
{
public:
	Settings();
	virtual ~Settings();

	std::string get(const std::string &) const;
	std::string operator[](const std::string &) const;
	void add(const std::string &, const std::string &);

private:
	std::map<std::string, std::string> data;
};

