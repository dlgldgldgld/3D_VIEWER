#pragma once

#include "ThreeDOReader.h"
#include "CGGroup.h"

namespace myviewer
{
	constexpr int FILE_BUFFER = 1024;

	enum eVIndex 
	{
		eVIndex_X = 1,
		eVIndex_Y = 2,
		eVIndex_Z = 3,
		eVIndex_W = 4
	};

	enum eVTIndex
	{
		eVTIndex_U = 1,
		eVTIndex_V = 2,
		eVTIndex_M = 3
	};

	enum eVNIndex
	{
		eVNIndex_X = 1,
		eVNIndex_Y = 2,
		eVNIndex_Z = 3
	};

	enum eFaceIndex
	{
		eFaceIndex_V = 1,
		eFaceIndex_VT = 2,
		eFaceIndex_VN = 3
	};

	class OBJReader : public ThreeDOReader
	{
	private :
		std::vector < CGGroup > m_groupList;

		bool GetVertex( const char * const contents );

		bool GetTextureCoord( const char * const contents );

		bool GetNormalCoord( const char * const contents );

		bool GetParameterSpace( const char * const contents );

		bool GetFaceElement( const char * const contents );

		bool GetLineElement( const char * const contents );

		int  GetAllMtlCount( );
	public : 
		 OBJReader( );
		~OBJReader( );

		bool FileRead ( ) override;
		bool Convert ( ) override ;

	};
}