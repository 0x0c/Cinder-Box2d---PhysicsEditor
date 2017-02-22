#pragma once
#include "b2cinder/Conversions.h"
#include "b2cinder/PhysicsElement.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/app/App.h"
#include "cinder/gl/Texture.h"

#include "Elements.h"

namespace cinder{
	namespace box2d {

	typedef boost::shared_ptr<class PolyElement> PolyElementRef;

	class PolyElement : public ci::box2d::PhysicsElement{
	public:
		PolyElement( b2World * world, vec2 pos, Elements::Body body );
		virtual ~PolyElement();

		virtual void draw();

		float getWidth();
		float getHeight();
		vec2 getSize();

		inline void setVisible( bool visible = true ){ mVisible = visible;};
		inline bool getVisible(){ return mVisible; };
	protected:
		b2PolygonShape	mShape;
		ci::gl::TextureRef mTexture;

		float			mWidth;
		float			mHeight;

		std::string		mName;

		bool			mVisible;
	};
}

}
