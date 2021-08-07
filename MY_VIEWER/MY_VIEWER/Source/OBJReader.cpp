#include "OBJReader.h"
#include <cassert>
#include <string.h>

bool myviewer::OBJReader::GetVertex( const char * const contents )
{
	int v_idx = 0;
	
	char seps[] = " ";
	char * v_token = nullptr ;
	char * next_token = nullptr;

	double v_value = 0.0 ;
	vUnit vertex;

	v_token = strtok_s( const_cast<char *> (contents), seps, & next_token ) ;
	while ( 1 )
	{
		if ( v_token == nullptr )
		{
			break;
		}

		v_idx++;
		v_value = atof( v_token ) ;
		switch ( v_idx )
		{
		case eVIndex::eVIndex_X :
			vertex.SetX( v_value );
			break ;
		case eVIndex::eVIndex_Y :
			vertex.SetY( v_value );
			break;
		case eVIndex::eVIndex_Z :
			vertex.SetZ( v_value );
			break;
		case eVIndex::eVIndex_W:
			// #TODO : W 좌표계 사용시 구현 필요함.
			break;
		}
		
		v_token = strtok_s( NULL , seps, & next_token ) ;
	}
	
	m_vList.push_back( vertex );
	return true;
}

bool myviewer::OBJReader::GetTextureCoord(const char * const contents)
{
	int v_idx = 0;

	char seps[] = " ";
	char * v_token = nullptr;
	char * next_token = nullptr;

	double v_value = 0.0;
	vtUnit vertex;

	v_token = strtok_s(const_cast<char *> (contents), seps, &next_token);
	while (1)
	{
		if (v_token == nullptr)
		{
			break;
		}

		v_idx++;
		v_value = atof(v_token);
		switch (v_idx)
		{
		case eVTIndex::eVTIndex_U:
			vertex.SetX(v_value);
			break;
		case eVTIndex::eVTIndex_V:
			vertex.SetY(v_value);
			break;
		case eVTIndex::eVTIndex_M:
			// #TODO : M 좌표계 사용시 구현 필요함.
			break;
		}

		v_token = strtok_s(NULL, seps, &next_token);
	}

	m_vtList.push_back(vertex);
	return true;
}

bool myviewer::OBJReader::GetNormalCoord(const char * const contents)
{
	int v_idx = 0;

	char seps[] = " ";
	char * v_token = nullptr;
	char * next_token = nullptr;

	double v_value = 0.0;
	vnUnit vertex;

	v_token = strtok_s(const_cast<char *> (contents), seps, &next_token);
	while (1)
	{
		if (v_token == nullptr)
		{
			break;
		}

		v_idx++;
		v_value = atof(v_token);
		switch (v_idx)
		{
		case eVNIndex::eVNIndex_X:
			vertex.SetX(v_value);
			break;
		case eVNIndex::eVNIndex_Y:
			vertex.SetY(v_value);
			break;
		case eVNIndex::eVNIndex_Z:
			vertex.SetZ(v_value);
			// #TODO : M 좌표계 사용시 구현 필요함.
			break;
		}

		v_token = strtok_s(NULL, seps, &next_token);
	}

	m_vnList.push_back(vertex);
	return true;
}

bool myviewer::OBJReader::GetFaceElement(const char * const contents)
{
	// ex ) f 3/1 4/2 5/3 
	// face list 분리용
	char f_seps [] = " "; 
	// elements 분리용
	char f_seps2[] = "/";

	char * facelist_token = nullptr;
	char * next_facelist_token = nullptr;

	char * face_element_token = nullptr;
	char * next_face_element_token = nullptr;

	int f_value = 0;

	CGFaceElement face_element;
	facelist_token = strtok_s(const_cast<char *> ( contents ), f_seps, &next_facelist_token);

	while ( 1 ) 
	{
		CGFace face_value;
		int f_idx = 0;
		if (facelist_token == nullptr)
		{
			break;
		}
		face_element_token = strtok_s( facelist_token, f_seps2, &next_face_element_token );
		
		while ( 1 ) 
		{
			if (face_element_token == nullptr)
			{
				break;
			}

			f_idx++;
			f_value = atoi( face_element_token );
			switch ( f_idx )
			{
			case eFaceIndex::eFaceIndex_V:
				face_value.vidx = f_value;
;				break;
			case eFaceIndex::eFaceIndex_VT:
				face_value.vtidx = f_value;
;				break;
			case eFaceIndex::eFaceIndex_VN:
				face_value.vnidx = f_value;
;				break;
			}

			face_element_token = strtok_s( nullptr, f_seps2, &next_face_element_token );
		}
		face_element.push_back(face_value);
		facelist_token = strtok_s( NULL , f_seps, &next_facelist_token);
	}

	m_faceList.push_back( face_element ) ;
	return true;
}

myviewer::OBJReader::OBJReader( )
{

}

myviewer::OBJReader::~OBJReader()
{

}

bool myviewer::OBJReader::FileRead( )
{
	char readBuffer[FILE_BUFFER];
	if (m_pfile == nullptr)
	{
		assert( ! ( m_pfile == nullptr ) ) ;
	}
	
	char seps[] = " \n";
	char * first_letter = nullptr;
	char * contents = nullptr;

	while (1)
	{
		bool isSuccess = false; 
		if ( fgets ( readBuffer, FILE_BUFFER, m_pfile ) == nullptr)
		{
			break;
		}

		first_letter = strtok_s(readBuffer, seps, &contents);
		
		if ( ( first_letter == NULL ) || 
		     ( strcmp( first_letter , "#" ) == 0 ) )
		{
			// ignore Comments line.
			continue;
		}
		else if ( strcmp( first_letter , "v" ) == 0 )
		{
			// vertex
			isSuccess = GetVertex ( contents );
		}
		else if ( strcmp( first_letter , "vt" ) == 0 )
		{
			// textureCoord
			isSuccess = GetTextureCoord(contents);
		}
		else if ( strcmp( first_letter , "vn" ) == 0)
		{
			// normal vector
			isSuccess = GetNormalCoord(contents);
		}
		else if ( strcmp( first_letter , "f" ) == 0)
		{
			isSuccess = GetFaceElement( contents );
			// face
		}
		else if ( strcmp( first_letter , "l" ) == 0)
		{
			// line
		}

		// Parsing False.
	}

	
	return true;
}

bool myviewer::OBJReader::Convert( )
{
	return true;
}

