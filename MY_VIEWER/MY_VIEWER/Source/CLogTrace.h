#pragma once

#include "CLogTraceType.h"
#include <string>
#include <stdio.h>

namespace logTrace
{

const char * const LOG_FILE_NAME = "log.txt";

class CLogTrace
{
private :
	bool   m_Init;
	FILE * m_outLog ;

	void Clear( );

public : 
	CLogTrace( ) ;
	virtual ~CLogTrace( ) ;

public  :
	bool Init( const char * filePath , const char * appName ) ;
	void WriteLog ( const logType & logType , char const * format, ... ) ;

};


}
