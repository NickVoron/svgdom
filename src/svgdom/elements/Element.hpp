#pragma once

#include <ostream>

#include <utki/Unique.hpp>

#include "Styleable.hpp"

namespace svgdom{

class Visitor;

/**
 * @brief Base class for all SVG document elements.
 */
struct Element :
		public utki::Unique,
		public Styleable //All SVG elements are Styleable according to SVG spec
{
	std::string id;
	
	virtual ~Element()noexcept{}
	
	//TODO: move all attribsToStream to cpp
	void attribsToStream(std::ostream& s)const;
	
	//TODO: implement via Visitor
	virtual void toStream(std::ostream& s, unsigned indent = 0)const = 0;
	
	//TODO: implement via Visitor
	std::string toString()const;
	
	/**
	 * @brief Accept method for Visitor pattern.
	 * @param visitor - visitor to accept.
	 */
	virtual void accept(Visitor& visitor)const = 0;
};

}