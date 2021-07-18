#pragma once

template <typename T>
class CGPoint3d
{
private :
	T m_x;
	T m_y;
	T m_z;

public :
	  CGPoint3d() = default;
	  ~CGPoint3d() = default;
	 CGPoint3d( const T & _x, const T & _y, const T & _z );

	void SetX(const T & _x );
	void SetY(const T & _y );
	void SetZ(const T & _z );
	
	T GetX( ) 
	{
		return m_x;
	}

	T GetY()
	{
		return m_y;
	}

	T GetZ()
	{
		return m_z;
	}

	CGPoint3d<T> operator+ (CGPoint3d<T> & rhs);
	CGPoint3d<T> operator= (CGPoint3d<T> & rhs);
	CGPoint3d<T> operator- (CGPoint3d<T> & rhs);
	
};

template <typename T>
CGPoint3d<T> CGPoint3d<T>::operator-(CGPoint3d<T> & rhs)
{
	CGPoint3d<T> res;
	res.m_x = this->m_x - rhs.GetX();
	res.m_y = this->m_y - rhs.GetX();
	res.m_z = this->m_z - rhs.GetX();
	return res;
}

template <typename T>
CGPoint3d<T> CGPoint3d<T>::operator=(CGPoint3d<T> & rhs)
{
	this->m_x = rhs.m_x;
	this->m_y = rhs.m_y;
	this->m_z = rhs.m_z;

	return this;
}

template <typename T>
CGPoint3d<T> CGPoint3d<T>::operator+(CGPoint3d<T> & rhs)
{
	CGPoint3d<T> res;
	res.m_x = this->m_x + rhs.GetX();
	res.m_y = this->m_y + rhs.GetX();
	res.m_z = this->m_z + rhs.GetX();
	return res;
}

template <typename T>
void CGPoint3d<T>::SetZ(const T & _z)
{
	m_z = _z;
}

template <typename T>
void CGPoint3d<T>::SetY(const T & _y)
{
	m_y = _y;
}

template <typename T>
void CGPoint3d<T>::SetX(const T & _x)
{
	m_x = _x;
}

template <typename T>
CGPoint3d<T>::CGPoint3d(const T & _x, const T & _y, const T & _z)
	: m_x ( _x )
	, m_y ( _y )
	, m_z ( _z )
{

}
