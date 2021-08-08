#pragma once
#include <string>
#include <vector>
#include <map>


using mtl_key = std::string;
using faceArray = std::vector<int>;
using mtl_map = std::map<mtl_key, faceArray>;

const char * const DEFAULT_GROUP_NAME = "GROUP_";

class CGGroup
{
public :
	CGGroup( ) 
	{
		
	};

	~CGGroup( )
	{
		Clear();
	};

	void Clear()
	{
		m_groupName.clear();
		m_mtlMap.clear();
	}

	void SetGroupNoName ( ) ;
	void SetGroupName( const char * _groupName ) ;
	void AddFaceListToMtlMap( mtl_key const & mtl_key , faceArray const & faceList ) ;

	size_t GetMtlMapSize( )
	{
		return m_mtlMap.size( );
	}
private :
	std::string m_groupName;
	mtl_map     m_mtlMap;
	static int m_noNameGroupCount;
};