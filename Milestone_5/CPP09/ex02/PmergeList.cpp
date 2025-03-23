#include "PmergeList.hpp"

PmergeList::PmergeList(int argc, char **argv)
{
	_startTime = clock();
	_size = 0;
	_oddNum = -1;

	for (int i = 1; i < argc; i += 2)
	{
		int convertedFirst = convertToInt(argv[i]);
		int convertedLast = (i + 1 < argc) ? convertToInt(argv[i + 1]) : -1;

		if (convertedFirst < 0 || convertedLast == -2)
			throw (std::invalid_argument("Error: invalid input"));
		if (convertedLast < 0)
		{
			_oddNum = convertedFirst;
			_size += 1;
		}
		else if (convertedFirst > convertedLast)
		{
			_pairs.push_back(std::make_pair(convertedFirst, convertedLast));
			_size += 2;
		}
		else
		{
			_pairs.push_back(std::make_pair(convertedLast, convertedFirst));
			_size += 2;
		}
	}
}

PmergeList::PmergeList(const PmergeList &source) : _oddNum(source._oddNum), _size(source._size), _insertionSequence(source._insertionSequence) {}

PmergeList &PmergeList::operator=(const PmergeList &source)
{
	if (this != &source)
	{
		_oddNum = source._oddNum;
		_size = source._size;
		_insertionSequence = source._insertionSequence;
	}

	return (*this);
}

PmergeList::~PmergeList() {}

//////////////////////////////////////////////////////////////////////////////////////

int PmergeList::convertToInt(char *numString)
{
	if (!numString)
		return -1;

	char *endptr;
	long value = std::strtol(numString, &endptr, 10);

	if (endptr == numString || *endptr != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return -2;

	return static_cast<int>(value);
}

void PmergeList::print(void) const
{
	std::cout << "Sorted list: ";
	for (std::list<int>::const_iterator it = _mainChain.begin(); it != _mainChain.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void PmergeList::generateInsertionSequence(void)
{
	std::list<int> jacobsthalSequence = generateJacobsthalSequence();
	std::list<int> insertion;

	if (!_pend.empty())
	{
		std::list<int>::iterator jacobIt = jacobsthalSequence.begin();
		std::advance(jacobIt, 3);// Move to the 4th element (index 3)

		insertion.push_back(*jacobIt);

		if (_pend.size() > 1)
			insertion.push_back(*jacobIt - 1);

		if (_pend.size() > 2)
		{
			size_t i = 1;
			int last = *jacobIt;
			std::list<int>::iterator pendIt = _pend.begin();

			std::advance(pendIt, 2);// Start from the 3rd element of _pend

			while (++i < _pend.size() && ++jacobIt != jacobsthalSequence.end())
			{
				insertion.push_back(*jacobIt);

				int num = *jacobIt;
				while (--num > last)
				{
					if (++i < _pend.size())
					{
						insertion.push_back(num);
					}
					else
					{
						break;// Break the loop if > list size
					}
				}
				last = *jacobIt;
			}
		}
	}
	_insertionSequence = insertion;
}

std::list<int> PmergeList::generateJacobsthalSequence(void)
{
	std::list<int> jacobsthal(_size);

	if (_size > 0)
		jacobsthal.push_back(0);
	if (_size > 1)
		jacobsthal.push_back(1);
	if (_size > 2)
	{
		std::list<int>::iterator prev2 = jacobsthal.begin();// Points to the 0th element
		std::list<int>::iterator prev1 = jacobsthal.begin();// Points to the 1st element (after ++)
		++prev1;

		for (int i = 2; i < _size; ++i)
		{
			int new_val = *prev1 + 2 * (*prev2);
			jacobsthal.push_back(new_val);

			++prev2;
			++prev1;
		}
	}

	return jacobsthal;
}

void PmergeList::sortPairs()
{
	_pairs.sort();
}

void PmergeList::divideChains()
{
	_mainChain.clear();
	_pend.clear();

	if (!_pairs.empty())
	{
		// Add the second element of the first pair to _mainChain
		_mainChain.push_back(_pairs.front().second);

		std::list<std::pair<int, int> >::iterator pairsIt = _pairs.begin();

		for (; pairsIt != _pairs.end(); ++pairsIt)
		{
			// Add the first element of each pair to _mainChain
			_mainChain.push_back(pairsIt->first);

			// Add the second element to _pend if it's not the first pair
			if (pairsIt != _pairs.begin())
			{
				_pend.push_back(pairsIt->second);
			}
		}
	}
}

std::list<int>::iterator	PmergeList::findPositionInMain(const int &i)
{
	std::list<int>::iterator it = _mainChain.begin();

	while (it != _mainChain.end() && *it < i)
		++it;

	return (it);
}

void PmergeList::insertSort()
{
	std::list<int>::iterator positionInMain;

	// Loop through the insertion sequence
	for (std::list<int>::iterator it = _insertionSequence.begin(); it != _insertionSequence.end(); ++it)
	{
		int index = *it - 2;
		if (index >= 0)
		{
			// Traverse _pend to get the value at the calculated index
			std::list<int>::iterator pendIt = _pend.begin();
			std::advance(pendIt, index);

			// Ensure the iterator is within bounds
			if (pendIt != _pend.end())
			{
				positionInMain = findPositionInMain(*pendIt);
				_mainChain.insert(positionInMain, *pendIt);
			}
		}
	}
	// Elements in _pend are inserted into _mainChain
	int i = (int)_pend.size();
	for (std::list<int>::iterator pendIt = _pend.end(); pendIt != _pend.begin(); pendIt--, i--)
	{
		if (std::find(_insertionSequence.begin(), _insertionSequence.end(), i + 2) == _insertionSequence.end())
		{
			positionInMain = findPositionInMain(*pendIt);
			_mainChain.insert(positionInMain, *pendIt);
		}
	}
	// Insert _oddNum if it's non-negative
	if (_oddNum >= 0)
	{
		positionInMain = findPositionInMain(_oddNum);
		_mainChain.insert(positionInMain, _oddNum);
	}

}

void PmergeList::mergeInsertSort()
{
	if (!_pairs.empty())
	{
		sortPairs();
		divideChains();
		generateInsertionSequence();
		insertSort();
	}
	else
	{
		std::list<int> mainChain(1, _oddNum);
	_mainChain = mainChain;
	}
	_endTime = clock();
}

void PmergeList::getTime(void) const
{
	double _duration = double(_endTime - _startTime) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with std::list : " <<  _duration * 1000 << " us" << std::endl;
}
