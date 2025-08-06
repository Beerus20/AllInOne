#ifndef TYPES_HPP
# define TYPES_HPP

# include <string>
# include <vector>
# include <map>

typedef std::string string;

struct Vector
{
	typedef std::vector<int>					integer;
	typedef std::vector<std::size_t>			size_t;
	typedef std::vector<std::string>			string;
};

template <typename T>
struct Map
{
	typedef std::map<T, int>					integer;
	typedef std::map<T, std::size_t>			size_t;
	typedef std::map<T, std::string>			string;

	struct vector
	{
		typedef std::map<T, Vector::integer>	integer;
		typedef std::map<T, Vector::size_t>		size_t;
		typedef std::map<T, Vector::string>		string;
	};
};

template <typename T>
struct Pair
{
	typedef std::pair<T, int>					integer;
	typedef std::pair<T, std::size_t>			size_t;
	typedef std::pair<T, std::string>			string;

	struct vector
	{
		typedef std::pair<T, Vector::integer>	integer;
		typedef std::pair<T, Vector::size_t>	size_t;
		typedef std::pair<T, Vector::string>	string;
	};
};
#endif