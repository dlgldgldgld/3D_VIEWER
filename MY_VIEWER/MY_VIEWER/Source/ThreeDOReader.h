#pragma once

#include <string>
#include "Common.h"

namespace myviewer
{
	class ThreeDOReader
	{
	private :
		std::string m_fileName ;

	protected : 
		FILE * m_pfile = nullptr;

	public : 
		ThreeDOReader( ) = default ;
		virtual ~ThreeDOReader( );

	private :
		bool FileOpen();
		bool Setting (__in const std::string & fileName);

	public : 
		bool Initialize( __in const std::string & fileName );
		virtual bool Convert ( ) = 0;

	};

}