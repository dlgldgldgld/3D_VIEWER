#pragma once

template <typename T>
class CGPoint
{
private :
	T x;
	T y;
	T z;

public :
	CGPoint( );
	~CGPoint( );

	CGPoint operator+ ( CGPoint & rhs );
	CGPoint operator= ( CGPoint & rhs );
	CGPoint operator- ( CGPoint & rhs );
};