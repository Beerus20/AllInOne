#ifndef UTILS_HPP
# define UTILS_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <map>
# include <vector>
# include "UtilsColors.hpp"
# include "../../includes/types.hpp"

class Utils
{
	public:
		virtual ~Utils(void);
		static std::ifstream	open(std::string const &path,  std::ios_base::openmode mode = std::ios_base::in);
		static Vector::string	split(std::string const &text, std::string const &separator = " ");
		template <typename T>
		static std::string		toString(const T &value);
		template <typename R, typename A>
		static R				convert(const A &value);

	private:
		Utils(void);
		Utils(const Utils&);
		Utils					&operator=(const Utils&);

};

template <typename T>
std::ostream& operator<<( std::ostream& os, const std::vector<T> &container);
template <typename K, typename V>
std::ostream& operator<<( std::ostream& os, const std::map<K, V> &container);
// std::ostream& operator<<( std::ostream& os, const Map<std::string>::string &fileparser);

# include "Utils.tpp"
# include "UtilsOutput.tpp"

#endif