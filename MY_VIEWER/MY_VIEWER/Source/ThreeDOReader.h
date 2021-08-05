#pragma once


#include <string>
#include <vector>
#include "CGVertexList.h"
#include "CGFace.h"

namespace myviewer
{
	class ThreeDOReader
	{
	private :
		std::string m_fileName ;

		vList  m_vList;
		vtList m_vtList;
		vnList m_vnList;

		CGFaceList m_faceList;

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
		virtual bool FileRead ( ) = 0;
		virtual bool Convert  ( ) = 0;

	};

}