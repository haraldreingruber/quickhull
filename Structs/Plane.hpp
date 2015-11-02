/*
 * Plane.hpp
 *
 *  Created on: Dec 7, 2013
 *      Author: anttiku
 */

#ifndef QHPLANE_HPP_
#define QHPLANE_HPP_

#include <OgreVector3.h>

namespace quickhull {

	template<typename T>
	class Plane {
	public:
		Ogre::Vector3 m_N;
		
		// Signed distance (if normal is of length 1) to the plane from origin
		T m_D;
		
		// Normal length squared
		T m_sqrNLength;

		bool isPointOnPositiveSide(const Ogre::Vector3& Q) const {
			T d = m_N.dotProduct(Q)+m_D;
			if (d>=0) return true;
			return false;
		}

		Plane() = default;

		// Construct a plane using normal N and any point P on the plane
		Plane(const Ogre::Vector3& N, const Ogre::Vector3& P) : m_N(N), m_D(-N.dotProduct(P)), m_sqrNLength(m_N.x*m_N.x+m_N.y*m_N.y+m_N.z*m_N.z) {
			
		}
	};

}


#endif /* PLANE_HPP_ */
