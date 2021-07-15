#pragma once

#include "CLogTraceType.h"
#include <string>
#include <stdio.h>

namespace logTrace
{

const char * const LOG_FILE_NAME = "log.txt";

class CLogTrace
{
private:
	CLogTrace();
	~CLogTrace();

private :
	bool   m_Init;
	FILE * m_outLog ;

	static CLogTrace * m_pInst;



public : 
	void Clear( );
	static CLogTrace* GetInstance( );
	static void DestroyInstance( );

public  :
	bool Init( const char * filePath , const char * appName ) ;
	void WriteLog ( const logType & logType , char const * format, ... ) ;

};


}
