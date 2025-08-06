#include "Utils.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &container)
{
	os << "(" << Color::Blue << container.size() << ") [";
	for (typename std::vector<T>::const_iterator it(container.begin()); it != container.end(); it++)
	{
		os << Color::green(*it);
		if (it + 1 != container.end())
			os << ", ";
	}
	os << "]" << std::endl;
	return (os);
}

template <typename K, typename V>
std::ostream& operator<<( std::ostream& os, const std::map<K, V> &container)
{
	for (typename std::map<K, V>::const_iterator it(container.begin()); it != container.end(); it++)
		os << "[ " << Color::blue(it->first) << " ] : " << Color::green(it->second) << std::endl;
	return (os);
}
