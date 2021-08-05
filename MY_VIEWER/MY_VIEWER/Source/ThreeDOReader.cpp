#include "ThreeDOReader.h"

myviewer::ThreeDOReader::~ThreeDOReader()
{
	if ( m_pfile != nullptr )
	{
		fclose(m_pfile);
		m_pfile = nullptr;
	}

	m_vList.clear();
	m_vnList.clear();
	m_vtList.clear();
}

bool myviewer::ThreeDOReader::FileOpen()
{
	fopen_s(&m_pfile, m_fileName.c_str(), "r");
	if (m_pfile == nullptr)
	{
		return false;
	}

	return true;
}

bool myviewer::ThreeDOReader::Setting( __in const std::string & fileName )
{
	m_fileName = fileName;
	return true;
}

bool myviewer::ThreeDOReader::Initialize(__in const std::string & fileName)
{
	if ( false == Setting( fileName ) )
	{
		return false;
	}

	if ( false == FileOpen( ) )
	{
		return false;
	}

	return true;
}
