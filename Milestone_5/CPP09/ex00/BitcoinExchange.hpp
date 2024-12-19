#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchangeRateMap;

		BitcoinExchange( void );
		void loadDatabase(std::ifstream &db);
		//void populateMap(const std::string &db);
		bool isValidDateFormat(const std::string &date);
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &value);
		void processQuery(std::string &date, std::string &value);

	public:
		BitcoinExchange( std::ifstream &databaseFile );
		BitcoinExchange( const BitcoinExchange &copy );
		BitcoinExchange &operator=( const BitcoinExchange &copy );
		~BitcoinExchange( void );

		void processInputFile(std::ifstream &inputFile);

};

#endif
