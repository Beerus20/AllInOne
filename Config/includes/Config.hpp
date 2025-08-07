#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include "../../Utils/includes/Utils.hpp"
# include "../../FileParser/includes/FileParser.hpp"

# define WINDOW_DEFAULT_CONFIG_FILE_PATH "./default/window.conf"
# define ENGINE_DEFAULT_CONFIG_FILE_PATH "./default/engine.conf"

class Config
{
	public:
		virtual ~Config(void);
		static void							load(void);
		static Map<std::string>::string		load(std::string const &file_path);
		static Map<std::string>::string		Window;
		static Map<std::string>::string		Engine;

	private:
		Config(void);
		Config(const Config&);
		Config				&operator=(const Config&);

};

#endif