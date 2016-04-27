#pragma once

#include <fstream>
#include <string>
#include "Settings.h"

namespace SettingsException
{
	struct NoSettingsFile : std::exception {};
}


namespace SettingsLoader
{
	extern Settings loadFromFile(std::string);
}