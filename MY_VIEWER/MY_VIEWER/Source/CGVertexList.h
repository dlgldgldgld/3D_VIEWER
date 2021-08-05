#pragma once

#include <vector>
#include "CGPoint3d.h"
#include "CGPoint2d.h" 

namespace myviewer
{
	using vUnit  = CGPoint3d<double>;
	using vtUnit = CGPoint2d<double>;
	using vnUnit  = CGPoint3d<double>;

	using vList  = std::vector < vUnit > ;
	using vtList = std::vector < vtUnit >;
	using vnList = std::vector < vnUnit >;

	
}