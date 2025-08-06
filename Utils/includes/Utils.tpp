#include "Utils.hpp"

template <typename T>
std::string Utils::toString(const T &value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

template <typename R, typename A>
R Utils::convert(const A &value)
{
	std::stringstream ss;
	R res;

	ss << value;
	ss >> res;

	return res;
}
