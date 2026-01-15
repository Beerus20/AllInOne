#include "../../include/data/Data.hpp"
#include <limits>

namespace One {
namespace Core {

	template <typename T>
	T Data::get(const std::string& key) const
	{
		return (this->_content.at(key).get<T>());
	}
	
	template <typename T>
	void Data::set(const std::string& key, const T& value)
	{
		this->_content[key] = value;
	}
	
	const Data& Data::get(void) const
	{
		return (static_cast<const Data&>(this->_content));
	}
	
	void Data::set(const Data& data)
	{
		this->_content = data;
	}
	
	// Explicit template instantiations
	template void Data::set<int>(const std::string& key, const int& value);
	template void Data::set<double>(const std::string& key, const double& value);
	template void Data::set<bool>(const std::string& key, const bool& value);
	template void Data::set<std::string>(const std::string& key, const std::string& value);
	template void Data::set<const char*>(const std::string& key, const char* const& value);
	
	template int Data::get<int>(const std::string& key) const;
	template double Data::get<double>(const std::string& key) const;
	template bool Data::get<bool>(const std::string& key) const;
	template std::string Data::get<std::string>(const std::string& key) const;
	template JSON Data::get<JSON>(const std::string& key) const;
	
} // namespace Core
}
