#pragma once

#include <string>

namespace myviewer
{
	class ThreeDOReader
	{
	private :
		std::string m_fileName ;

	public : 
		ThreeDOReader( ) = default ;
		virtual ~ThreeDOReader( );

	public : 
		bool Setting ( __in const std::string & fileName ) ;
		virtual bool Convert ( ) = 0;

	};

}