#pragma once

#include "ThreeDOReader.h"

namespace myviewer
{
	class OBJReader : public ThreeDOReader
	{

	public : 
		bool Convert( ) override ;

	};
}