#pragma once
#include "b2cinder/Conversions.h"
#include "b2cinder/PhysicsElement.h"

#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/app/App.h"
#include "cinder/Xml.h"

namespace cinder{
	namespace box2d {

	typedef boost::shared_ptr<class Elements> ElementsRef;

	class Elements {
	public:
		struct Polygon{
			std::vector<vec2> vertexes;
		};
		struct Circle{
			float		radius;
			vec2	position;
		};
		struct Fixture{
			std::vector<Polygon>	polygons;
			std::vector<Circle>		circles;

			uint16 maskBits;
			uint16 catagoryBits;

			float	density;
			float	restitution;
			float	friction;
			bool	isSensor;

			std::string type;
		};
		struct Body{
			std::string name;
			bool isDynamic;
			std::vector<Fixture> fixtures;
		};
	public:
		Elements();
		~Elements();

		void setup( DataSourceRef file );

		inline const Body& getElement(std::string id){ return mElements[id]; };
		inline const std::map<std::string, Elements::Body> &getElements(){ return mElements; };
	private:
		std::map<std::string, Elements::Body> mElements;
	};

	typedef std::map<std::string, Elements::Body> ElementsList;
}

}
