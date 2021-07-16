
#include "fileManager.h"

myviewer::fileManager::fileManager( )
{

}

myviewer::fileManager::~fileManager( )
{

}

int main(void)
{
	myviewer::pLog = logTrace::CLogTrace::GetInstance( );
	myviewer::pLog->Init( "D:\\01.Develop\\01.CPP\\01.PROJECT\\aaa" , "myviewer" );
	myviewer::pLog->WriteLog(logTrace::logType::LogStatus, "Start Program" ) ;


	myviewer::pLog->DestroyInstance( );
	return 0;
}