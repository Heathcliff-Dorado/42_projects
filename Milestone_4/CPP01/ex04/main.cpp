#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv) {

	if (argc != 4)
	{
		std::cout << "Error, usage is ./Replacer <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string	filename(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	std::ifstream	input(filename.c_str());
	if (!input)
	{
		std::cout << "Error, filename provided could not be opened" <<std::endl;
		return (1);
	}
	std::ofstream	output((filename + ".replace").c_str());
	if (!output)
	{
		std::cout << "Error opening the filename.replace file" <<std::endl;
		return (1);
	}
	std::string	line;
	while (std::getline(input, line))
	{
		size_t	i;
		while ((i = line.find(s1)) != std::string::npos)
			line = line.substr(0, i) + s2 + line.substr(i + s1.length());
		output << line <<std::endl;
	}
	input.close();
	output.close();
	return (0);
}
