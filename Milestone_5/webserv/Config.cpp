#include "Config.hpp"

//default constructor (only for orthodox form)
Config::Config( void ) {
	parseConfigFile("default.conf");
}

//Copy constructor
Config::Config( const Config& copy) {
	*this = copy;
}

//Equal operator
Config&	Config::operator=( const Config& copy) {
	if (this != &copy)
	{
		return (*this);
	}

	return (*this);
}

//Deconstructor
Config::~Config() {
}

//Constructor that takes a configFile as argument
Config::Config( const std::string& configFile) {
	parseConfigFile(configFile);
}

//Parses the config file and populates all the attributes of the Config class
void	parseConfigFile(const std::string &configFile)
{
	//Checks if the file is accessible
	std::ifstream(configFile)
	if (!configFile.is_open())
	{
		std::cerr << "Error: Unable to open file " << configFile << std::endl;
		return ;
	}

	//reads line by line, gets the key and value (must follow structure key=value)
	std::string	line;
	while (getLine(configFile, line))
	{
		size_t	start = line.find_first_not_of(" \t");
		size_t	end = line.find_last_not_of(" \t");

		//Skip empty lines
		if (start == std::string::npos || end == std::string::npos)
			continue;
		line = line.substr(start, end - start + 1);
		if (line.empty() || line[0] == '#')
			continue;

		//Extracts the key=value pairs
		size_t pos = line.find(' ');
		if (pos != std::string::npos)
		{
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 1);
			key = key.substr(key.find_first_not_of(" \t"), key.find_last_not_of(" \t"));
			value = value.substr(value.find_first_not_of(" \t"), value.find_last_not_of(" \t"));
			if (key == "error_page")
			{
				size_t pos2 = value.find(' ');
				std::string pg_errno = value.substr(0, pos2);
				std::string pg_dir = valie.substr(pos2 + 1);
				_error_pages[pg_errno] = pg_dir;
			}
			else
				_settings[key] = value;
		}
	}
	file.close();
	//Get port number
	_port = std::stoi(settings["port"]);

	// Get the root directory
	_root = _settings["root_directory"];

	// Get allowed methods and parse into vector methods
	_allowed_methods = _settings["allowed_methods"];
	std::stringstream ss(allowed_methods);
	std::string method;
	while (getline(ss, method, ','))
		_methods.push_back(method);

	//Here I would run isValid() to check if all essential info is there. isValid should also add as default those that are missing and a default is available
	_valid = true;
}
