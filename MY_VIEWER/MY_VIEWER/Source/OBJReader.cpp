#include "OBJReader.h"

bool myviewer::OBJReader::FileOpen()
{
	fopen_s( &m_pfile, m_fileName.c_str(), "r" ) ;
	if ( m_pfile == nullptr )
	{
		return false;
	}
	return true;
}

myviewer::OBJReader::OBJReader( )
	: m_pfile ( nullptr )
{

}

myviewer::OBJReader::~OBJReader()
{

}

bool myviewer::OBJReader::Convert( )
{
	return true;
}

