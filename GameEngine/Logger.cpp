#include "Logger.h"

namespace Logger
{
	void log(const std::string & text)
	{
		std::cout << "[DEBUG]" << text << std::endl;
	}
}
