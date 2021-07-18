#pragma once
#include <vector>

 typedef struct CGFace
{
	 int vidx;
	 int vtidx;
	 int vnidx;

	 CGFace( )
		 : vidx ( -1 )
		 , vtidx ( -1 )
		 , vnidx ( -1 )
	 {

	 }
} CGFace ;

 using CGFaceList = std::vector< CGFace >;
 