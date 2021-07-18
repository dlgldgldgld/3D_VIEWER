#pragma once
#include <vector>
#include "CGPoint3d.h"
#include "CGPoint2d.h"
#include "CGFace.h"

class Geoemtry
{
private : 

	bool m_useVertex;
	bool m_useTexcoord;
	bool m_useNormal;

	std::vector < CGPoint3d < double > > m_vertex;
	std::vector < CGPoint2d < double > > m_textureCoord;
	std::vector < CGPoint3d < double > > m_normal;

	CGFaceList m_face;
	
public :

	Geoemtry()
		: m_useVertex(false)
		, m_useTexcoord(false)
		, m_useNormal(false)
	{

	}

	~Geoemtry()
	{
		m_vertex.clear();
		m_textureCoord.clear();
		m_normal.clear();
	}

	bool IsUsingVertex( )
	{
		return m_useVertex;
	}

	bool IsUsingTexture()
	{
		return m_useTexcoord;
	}

	bool IsUsingNormal()
	{
		return m_useNormal;
	}

	void SetUseVertex( const bool useFlag )
	{
		m_useVertex = useFlag;
	}

	void SetUseTexture( const bool useFlag )
	{
		m_useTexcoord = useFlag;
	}

	void SetUseNormal( const bool useFlag )
	{
		m_useNormal = useFlag;
	}

	size_t GetFaceSize( )
	{
		return m_face.size( );
	}

};