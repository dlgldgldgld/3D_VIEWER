#pragma once

#include "stdint.h"
#include <string>

namespace myviewer
{
	enum class fileext : uint8_t
	{
		eWaveFront = 0,
		eCollada   = 1,
		DEFAULT    = 2
	};

	const char * fileExtToString ( const fileext & ext )
	{
		switch (ext)
		{
		case fileext::eWaveFront :
			return "WaveFront";
			break;
		case fileext::eCollada   :
			return "Collada";
			break;
		default :
			return "Not Defined";
			break;
		}

		return "Not Defined" ;
	}

}