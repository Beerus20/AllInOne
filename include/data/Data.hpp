#pragma once

# include <string>
# include "json.hpp"

using JSON = nlohmann::json;

namespace One {
/**
 * @brief Data management
 * Functions for loading and saving data
 */
class Data : public JSON {
	private:
		JSON	_content;

	public:
		Data();
		~Data();
		
		Data(const JSON& json);
		Data(const std::string& file_path);
		Data(const Data& other);
		
		Data&			operator=(const Data& other);

		template <typename T>
		T				get(const std::string& key) const;
		const Data&		get(void) const;
		template <typename T>
		void			set(const std::string& key, const T& value);
		void			set(const Data& data);

		bool			load(const std::string& filepath);
		template <typename T>
		bool			load(const std::string& filepath, T& outJson);
		bool			save(const std::string& filepath, const Data& data);
		bool			save(const std::string& filepath, const std::string& content);
		
	// Display methods
	std::string		dump(int indent = 4) const;
	std::string		toString() const;
	std::string		toColoredString() const;
	
}; // namespace One	
}
std::ostream&	operator<<(std::ostream& os, const One::Data& data);