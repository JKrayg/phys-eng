
#include <string>
#include "quaternion.h"


std::string Quaternion::to_string() const {
	return "[" + std::to_string(w) +
		", " + std::to_string(x) +
		", " + std::to_string(y) +
		", " + std::to_string(z) + "]";
}