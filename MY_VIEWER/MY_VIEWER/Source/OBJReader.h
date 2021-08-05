#pragma once

#include "ThreeDOReader.h"

namespace myviewer
{
	class OBJReader : public ThreeDOReader
	{
	private :
		

	public : 
		 OBJReader( );
		~OBJReader( );

		bool FileRead ( ) override;
		bool Convert ( ) override ;

	};
}