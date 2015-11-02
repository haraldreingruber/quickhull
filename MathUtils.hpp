
#ifndef QuickHull_MathUtils_hpp
#define QuickHull_MathUtils_hpp

#include <OgreVector3.h>
#include "Structs/Ray.hpp"

namespace quickhull {
	
	namespace mathutils {
		
		template <typename T>
		inline T getSquaredDistanceBetweenPointAndRay(const Ogre::Vector3& p, const Ray<T>& r) {
			Ogre::Vector3 s = (p-r.m_S);
			T t = s.dotProduct(r.m_V);
			return s.squaredLength() - t*t/(r.m_V.squaredLength());
		}
		
		// Note that the unit of distance returned is relative to plane's normal's length.
		template <typename T>
		inline T getSignedDistanceToPlane(const Ogre::Vector3& v, const Plane<T>& p) {
			return p.m_N.dotProduct(v) + p.m_D;
		}
		
		template <typename T>
		inline Ogre::Vector3 getTriangleNormal(const Ogre::Vector3& a,const Ogre::Vector3& b,const Ogre::Vector3& c) {
			// We want to get (a-c).crossProduct(b-c) without constructing temp vectors
			T x = a.x - c.x;
			T y = a.y - c.y;
			T z = a.z - c.z;
			T rhsx = b.x - c.x;
			T rhsy = b.y - c.y;
			T rhsz = b.z - c.z;
			T px = y * rhsz - z * rhsy ;
			T py = z * rhsx - x * rhsz ;
			T pz = x * rhsy - y * rhsx ;
			return Ogre::Vector3(px,py,pz);
		}
		
		
	}
	
}


#endif
