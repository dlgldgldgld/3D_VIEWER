#include "CLogTrace.h"
#include <windows.h> 
#include <io.h>
#include <time.h>

void logTrace::CLogTrace::Clear()
{
	if ( m_outLog != nullptr )
	{
		fclose( m_outLog );
	}
}

logTrace::CLogTrace::CLogTrace( )
	: m_outLog ( nullptr )
	, m_Init ( false )
{

}

logTrace::CLogTrace::~CLogTrace()
{
	Clear( );
}

bool logTrace::CLogTrace::Init( const char * filePath , const char * appName)
{
	std::string logFilePath ;
	logFilePath.append ( filePath  ) ;
	logFilePath.append ( "/" ) ;
	logFilePath.append ( appName ) ;
	logFilePath.append ( "_" ) ;
	logFilePath.append ( LOG_FILE_NAME ) ;

	if (    0 == _access( logFilePath.c_str( ), 0 ) 
		&& -1 == _unlink( logFilePath.c_str( ) ) )
	{
		printf("%s logFile Delete Fail!!\n", logFilePath.c_str( ) ) ;
		return false;
	}

	fopen_s(&m_outLog, logFilePath.c_str(), "w+" ) ;
	if ( m_outLog == nullptr )
	{
		printf("file_open fail.. \n");
		return false;
	}

	return true;
}

void logTrace::CLogTrace::WriteLog( const logType & logType, char const * format , ... )
{
	// Get Current Time
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	localtime_s(&tstruct, &now);
	strftime( buf, sizeof (buf), "%Y-%m-%d %X", & tstruct );

	// Set LogColor
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( hConsole, LOG_COLOR [ logType ] ) ;

	va_list argptr;
	va_start ( argptr, format );
	
	printf ( "[ %s ] - ", buf ) ;
	vprintf( format, argptr ) ;
	printf ( "\n" ) ;

	fprintf( m_outLog, "[ %s ] - ", buf ) ;
	vfprintf_s( m_outLog, format , argptr);
	fprintf( m_outLog, "\n" ) ;
	va_end( argptr );
	return;
}