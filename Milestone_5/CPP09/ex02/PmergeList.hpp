#ifndef PMERGELIST_HPP
#define PMERGELIST_HPP

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <utility>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class PmergeList
{
	private:
		int _oddNum;
		int _size;
		std::list<int> _mainChain;
		std::list<int> _pend;
		std::list<std::pair<int, int> > _pairs;
		std::list<int> _insertionSequence;
		clock_t _startTime, _endTime;

		int convertToInt(char *numString);
		void sortPairs();
		void divideChains();
		void generateInsertionSequence(void);
		std::list<int> generateJacobsthalSequence(void);
		void insertSort();
		std::list<int>::iterator findPositionInMain(const int &i);

	public:
		PmergeList(int argc, char **argv);
		PmergeList(const PmergeList &source);
		PmergeList &operator=(const PmergeList &source);
		~PmergeList(void);

		void mergeInsertSort();
		void print(void) const;
		void getTime(void) const;
};

#endif // PMERGELIST_HPP
