#include "ThreeDOReader.h"

myviewer::ThreeDOReader::~ThreeDOReader()
{

}

bool myviewer::ThreeDOReader::Setting( __in const std::string & fileName)
{
	m_fileName = fileName;
	return true;
}
