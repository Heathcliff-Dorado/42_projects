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
void	Config::parseConfigFile(const std::string &configFile)
{
	//Checks if the file is accessible
	std::ifstream conf(configFile);
	if (!conf)
	{
		std::cerr << "Error: Unable to open file " << configFile << std::endl;
		return ;
	}

	//reads line by line, extracts all parameters and location blocks
	std::string	line;
	while (getline(conf, line))
	{
		//Trim lines and get rid of empty ones
		size_t	start = line.find_first_not_of(" \t");
		size_t	end = line.find_last_not_of(" \t");

		if (start == std::string::npos || end == std::string::npos)
			continue;
		line = line.substr(start, end - start + 1);
		if (line.empty() || line[0] == '#')
			continue;

		//Look for info, locations have space separators, while parameters have \t
		size_t pos = line.find('\t');
		if (pos != std::string::npos) //if pos == npos, this is a line with a location block or some error, so we skip this loop
		{
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 1, line.length() - 1); //To avoid the ; in the end
			key = key.substr(key.find_first_not_of(" \t"), key.find_last_not_of(" \t"));
			value = value.substr(value.find_first_not_of(" \t"), value.find_last_not_of(" \t"));
			_settings[key] = value;
		}
		size_t pos = line.find(' ');
		if (pos != std::string::npos) //if pos == npos, this is a line with a parameter (so already done) or error (so skip)
		{
			std::string location = line.substr(pos + 1, location.length() - 2);
			while (getline(conf, line))
			{
				start = line.find_first_not_of(" \t");
				end = line.find_last_not_of(" \t");
				if (line == "}")
					continue;
				//Need to parse all the arguments from the location block, store into a struct ?
			}
		}
	}
	conf.close();
	//Get port number
	_port = std::stoi(_settings["port"]);

	// Get the root directory
	_root = _settings["root_directory"];

	// Get allowed methods and parse into vector methods
	_allowed_methods = _settings["allowed_methods"];
	std::stringstream ss(_allowed_methods);
	std::string method;
	while (getline(ss, method, ','))
		_methods.push_back(method);

	//Here I would run isValid() to check if all essential info is there. isValid should also add as default those that are missing and a default is available
	_valid = true;
}
