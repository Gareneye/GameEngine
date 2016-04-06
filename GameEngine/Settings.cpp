#include "Settings.h"



Settings::Settings()
{
}


Settings::~Settings()
{
}

std::string Settings::get(const std::string & title) const
{
	return data.at(title);
}

void Settings::add(const std::string & title, const std::string & value)
{
	data.insert(std::pair<std::string, std::string>(title, value));

	Logger::log("Added to settings: [" + title + "] " + value);
}
