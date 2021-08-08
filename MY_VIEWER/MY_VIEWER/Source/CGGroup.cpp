#include "CGGroup.h"

int CGGroup::m_noNameGroupCount = 0;

void CGGroup::SetGroupNoName( )
{
	m_groupName = DEFAULT_GROUP_NAME ;
	m_groupName.append ( std::to_string( m_noNameGroupCount++ ) ) ;
}

void CGGroup::SetGroupName( const char * _groupName )
{
	m_groupName = _groupName;
}

void CGGroup::AddFaceListToMtlMap(mtl_key const & mtl_key, faceArray const & faceList)
{
	auto mtlIter = m_mtlMap.find( mtl_key );
	if ( mtlIter != m_mtlMap.end( ) )
	{
		for ( const auto & element : faceList )
		{
			mtlIter->second.push_back( element ) ;
		}
	}
	else
	{
		// if no exists mtl_key, face list load into mtlMap.
		m_mtlMap.insert(
			decltype(m_mtlMap)::value_type( mtl_key, faceList )
		);
	}

}
