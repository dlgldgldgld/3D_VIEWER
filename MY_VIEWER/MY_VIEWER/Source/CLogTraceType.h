#pragma once
#include <stdint.h>

namespace logTrace
{
	enum logType
	{
		LogError   = 0 ,
		LogStatus  = 1 ,
		LogWarning = 2 ,
		Default    = 3
	};
	
	constexpr int LOG_COLOR[ logType::Default ] = { 12, 15, 14 };

}