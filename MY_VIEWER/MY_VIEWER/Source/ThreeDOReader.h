#pragma once


#include <string>
#include <vector>
#include "CGVertexList.h"
#include "CGFace.h"

namespace myviewer
{
	class ThreeDOReader
	{
	protected : 
		std::string m_fileName;

		// 21-08-08 : yejlee 
		// below varients should be divide other structure.
		// because ThreeDOReader only have to parse ObjectFile, don't need to have result data. result data.
		// It based on SOLID rule.

		vList  m_vList;
		vtList m_vtList;
		vnList m_vnList;
		CGFaceList m_faceList;
		//

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
		virtual bool Convert  ( ) = 0; // openGL 

		// 
	};

}