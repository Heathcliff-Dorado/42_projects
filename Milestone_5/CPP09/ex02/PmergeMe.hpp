#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <utility>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		int _oddNum;
		int _size;
		std::vector<int> _mainChain;
		std::vector<int> _pend;
		std::vector<std::pair<int, int> > _pairs;
		std::vector<int> _insertionSequence;
		clock_t _startTime, _endTime;

		int convertToInt(char *numString);
		void sortPairs();
		void divideChains();
		void generateInsertionSequence(void);
		std::vector<int> generateJacobsthalSequence(void);
		void insertSort();
		std::vector<int>::iterator findPositionInMain(const int &i);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &source);
		PmergeMe &operator=(const PmergeMe &source);
		~PmergeMe(void);

		void mergeInsertSort();
		void print(void) const;
		void getTime(void) const;

};

#endif // PMERGEME_HPP
