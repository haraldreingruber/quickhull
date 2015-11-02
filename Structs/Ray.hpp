#ifndef QuickHull_Ray_hpp
#define QuickHull_Ray_hpp

#include <OgreVector3.h>

namespace quickhull {

	template <typename T>
	struct Ray {
		Ogre::Vector3 m_S;
		Ogre::Vector3 m_V;
		Ray() {}
		Ray(const Ogre::Vector3& S,const Ogre::Vector3& V) : m_S(S), m_V(V) {
		}
	};
	
}


#endif
