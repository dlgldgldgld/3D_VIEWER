#include "ThreeDOReader.h"

myviewer::ThreeDOReader::~ThreeDOReader()
{

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
		pLog->WriteLog(logTrace::logType::LogError, "SetFile Error." );
		return false;
	}

	if (false == FileOpen( ) )
	{
		pLog->WriteLog(logTrace::logType::LogError, "%s file open and read Fail!", fileName.c_str( ) ) ;
		return false;
	}

	return true;
}
