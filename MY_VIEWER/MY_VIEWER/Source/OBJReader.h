#pragma once

#include "ThreeDOReader.h"

namespace myviewer
{
	class OBJReader : public ThreeDOReader
	{
	private :
		FILE * m_pfile = nullptr;

		bool FileOpen( ) ;

	public : 
		 OBJReader( );
		~OBJReader( );

		bool Convert( ) override ;

	};
}