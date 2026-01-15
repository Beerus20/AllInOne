#include "../../include/data/Data.hpp"
#include <fstream>
#include <climits>

namespace One {
Data::Data() : _content(JSON::object()) {}
Data::~Data() {}
Data::Data(const JSON& json) : _content(json) {}
Data::Data(const std::string& file_path)
{
	load(file_path, _content);
}
Data::Data(const Data& other) : JSON(), _content(other._content) {}

Data& Data::operator=(const Data& other)
{
	if (this != &other) {
		_content = other._content;
	}
	return (*this);
}

bool Data::load(const std::string& filepath) 
{
	std::ifstream	file(filepath);
	
	if (!file.is_open())
		return (false);
	try
	{
		file >> this->_content;
	}
	catch (...)
	{
		file.close();
		return (false);
	}
	file.close();
	return (true);
}

template <typename T>
bool Data::load(const std::string& filepath, T& outJson)
{
	std::ifstream	file(filepath);
	
	if (!file.is_open())
		return (false);
	std::stringstream buffer;
	buffer << file.rdbuf();
	outJson = buffer.str();
	file.close();
	return (true);
}

bool Data::save(const std::string& filepath, const Data& data)
{
	std::ofstream	file(filepath);
	
	if (!file.is_open())
		return (false);
	try
	{
		file << data.dump(4);
	}
	catch (...)
	{
		file.close();
		return (false);
	}
	file.close();
	return (true);
}

bool Data::save(const std::string& filepath, const std::string& content)
{
	std::ofstream	file(filepath);
	
	if (!file.is_open())
		return (false);
	try
	{
		file << content;
	}
	catch (...)
	{
		file.close();
		return (false);
	}
	file.close();
	return (true);
}

std::string Data::dump(int indent) const
{
	try {
		return (_content.dump(indent));
	}
	catch (const std::exception& e) {
		return ("Error: Invalid JSON data");
	}
}

std::string Data::toString() const
{
	return (dump(4));
}

std::string Data::toColoredString() const
{
	// ANSI color codes
	const std::string RESET = "\033[0m";
	const std::string CYAN = "\033[36m";      // Keys
	const std::string GREEN = "\033[32m";     // String values
	const std::string YELLOW = "\033[33m";    // Numbers
	const std::string MAGENTA = "\033[35m";   // Booleans
	const std::string RED = "\033[31m";       // Null
	const std::string GRAY = "\033[90m";      // Brackets and commas
	
	std::string json = dump(4);
	std::string result;
	bool inKey = false;
	bool inString = false;
	bool escaped = false;
	
	for (size_t i = 0; i < json.length(); ++i) {
		char c = json[i];
		
		if (escaped) {
			result += c;
			escaped = false;
			continue;
		}
		
		if (c == '\\') {
			escaped = true;
			result += c;
			continue;
		}
		
		if (c == '"') {
			if (!inString) {
				// Check if this is a key (followed by ':')
				size_t colonPos = json.find(':', i);
				size_t nextQuote = json.find('"', i + 1);
				if (colonPos != std::string::npos && colonPos < json.find('\n', i) && 
					colonPos == nextQuote + 1) {
					result += CYAN + c;
					inKey = true;
				} else {
					result += GREEN + c;
				}
				inString = true;
			} else {
				result += c;
				if (inKey) {
					result += RESET;
					inKey = false;
				} else {
					result += RESET;
				}
				inString = false;
			}
		} else if (!inString) {
			// Colorize numbers
			if (std::isdigit(c) || (c == '-' && i + 1 < json.length() && std::isdigit(json[i + 1]))) {
				result += YELLOW + c;
				size_t j = i + 1;
				while (j < json.length() && (std::isdigit(json[j]) || json[j] == '.')) {
					result += json[j++];
				}
				result += RESET;
				i = j - 1;
			}
			// Colorize booleans
			else if (json.substr(i, 4) == "true" || json.substr(i, 5) == "false") {
				size_t len = (json.substr(i, 4) == "true") ? 4 : 5;
				result += MAGENTA + json.substr(i, len) + RESET;
				i += len - 1;
			}
			// Colorize null
			else if (json.substr(i, 4) == "null") {
				result += RED + "null" + RESET;
				i += 3;
			}
			// Colorize brackets and structural elements
			else if (c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || c == ':') {
				result += GRAY + c + RESET;
			} else {
				result += c;
			}
		} else {
			result += c;
		}
	}
	
	return result;
}

} // namespace One

std::ostream& operator<<(std::ostream& os, const One::Data& data)
{
	os << data.toColoredString();
	return (os);
}