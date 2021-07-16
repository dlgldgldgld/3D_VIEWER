#pragma once

template <typename T>
class CGPoint2d
{
private:
	T m_x;
	T m_y;

public:
	CGPoint2d() = default;
	~CGPoint2d() = default;
	CGPoint2d(const T & _x, const T & _y);

	void SetX(const T & _x);
	void SetY(const T & _y);

	T GetX()
	{
		return m_x;
	}

	T GetY()
	{
		return m_y;
	}


	CGPoint2d<T> operator+ (CGPoint2d<T> & rhs);
	CGPoint2d<T> operator= (CGPoint2d<T> & rhs);
	CGPoint2d<T> operator- (CGPoint2d<T> & rhs);

};

template <typename T>
CGPoint2d<T> CGPoint2d<T>::operator-(CGPoint2d<T> & rhs)
{
	CGPoint2d<T> res;
	res.m_x = this->m_x - rhs.GetX();
	res.m_y = this->m_y - rhs.GetX();
	return res;
}

template <typename T>
CGPoint2d<T> CGPoint2d<T>::operator=(CGPoint2d<T> & rhs)
{
	this->m_x = rhs.m_x;
	this->m_y = rhs.m_y;
	return this;
}

template <typename T>
CGPoint2d<T> CGPoint2d<T>::operator+(CGPoint2d<T> & rhs)
{
	CGPoint2d<T> res;
	res.m_x = this->m_x + rhs.GetX();
	res.m_y = this->m_y + rhs.GetX();
	return res;
}

template <typename T>
void CGPoint2d<T>::SetY(const T & _y)
{
	m_y = _y;
}

template <typename T>
void CGPoint2d<T>::SetX(const T & _x)
{
	m_x = _x;
}

template <typename T>
CGPoint2d<T>::CGPoint2d(const T & _x, const T & _y )
	: m_x(_x)
	, m_y(_y)
{

}
