#include "SettingsLoader.h"

namespace SettingsLoader
{
	Settings SettingsLoader::loadFromFile(std::string filename)
	{
		std::fstream settingsFile;
		settingsFile.open(filename, std::ios::in);

		if (!settingsFile.good()) throw SettingsException::NoSettingsFile();

		Settings settingsObject;

		std::string lineBuffor;

		while (getline(settingsFile, lineBuffor))
		{
			unsigned int i = 0;
			std::string setting, value;

			// start of ID
			for (; i < lineBuffor.length(); ++i)
			{
				if (lineBuffor[i] == '[') break;
			}

			// end of ID
			for (++i; i < lineBuffor.length(); ++i)
			{
				if (lineBuffor[i] == ']') break;
				if (lineBuffor[i] == ' ') continue;
				setting += lineBuffor[i];
			}

			// Value
			for (++i; i < lineBuffor.length(); ++i)
			{
				if (lineBuffor[i] == ' ') continue;
				value += lineBuffor[i];
			}

			if (!setting.length() || !value.length())
				continue;

			// ADD SETTING
			settingsObject.add(setting, value);
		}

		return settingsObject;
	}

}

