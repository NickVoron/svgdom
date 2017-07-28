#pragma once

#include <vector>

#include "Element.hpp"

namespace svgdom{

/**
 * @brief An element which can have child elements.
 */
struct Container{
	std::vector<std::unique_ptr<Element>> children;

	/**
	 * @brief Relay accept to children.
	 * @param visitor - visitor to accept.
	 */
	void relayAccept(Visitor& visitor)const;
};

}
