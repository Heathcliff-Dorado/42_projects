#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
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

PmergeMe::PmergeMe(const PmergeMe &source) : _oddNum(source._oddNum), _size(source._size), _insertionSequence(source._insertionSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
	if (this != &source)
	{
		_oddNum = source._oddNum;
		_size = source._size;
		_insertionSequence = source._insertionSequence;
	}

	return (*this);
}

PmergeMe::~PmergeMe() {}

//////////////////////////////////////////////////////////////////////////////////////

int PmergeMe::convertToInt(char *numString)
{
	if (!numString)
		return -1;

	char *endptr;
	long value = std::strtol(numString, &endptr, 10);

	if (endptr == numString || *endptr != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return -2;

	return static_cast<int>(value);
}

void PmergeMe::print(void) const
{
	for (size_t i = 0; i < _mainChain.size(); i++)
	{
		std::cout << _mainChain[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::generateInsertionSequence(void)
{
	std::vector<int> jacobsthalSequence = generateJacobsthalSequence();
	std::vector<int> insertion(_pend.size());

	if (!_pend.empty())
	{
		insertion[0] = jacobsthalSequence[3];
		if (_pend.size() > 1)
			insertion[1] = jacobsthalSequence[3] - 1;

		if (_pend.size() > 2)
		{
			size_t i = 1, j = 3;
			int last = jacobsthalSequence[3];

			while (++i < _pend.size() && ++j < jacobsthalSequence.size())
			{
				insertion[i] = jacobsthalSequence[j];
				int num = insertion[i];
				while (--num > last)
				{
					if (++i < _pend.size())
					{
						insertion[i] = num;
					}
					else
					{
						break;// Break loop if > vector size
					}
				}
				last = jacobsthalSequence[j];
			}

		}
	}
	_insertionSequence = insertion;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(void)
{
	std::vector<int> jacobsthal(_size);

	if (_size > 0) jacobsthal[0] = 0;
	if (_size > 1) jacobsthal[1] = 1;

	for (int i = 2; i < _size; ++i)//first 2 nums are not needed ('0', '1') so we generate 2 nums extra on their place. needed?
	{
		jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
	}

	return jacobsthal;
}

void PmergeMe::sortPairs()
{
	std::sort(_pairs.begin(), _pairs.end());
}


void PmergeMe::divideChains()
{
	std::vector<int> mainChain(_pairs.size() + 1);
	std::vector<int> pend((_pairs.size() > 1) ? _pairs.size() - 1 : 0);

	_mainChain = mainChain;
	_pend = pend;

	if (_pairs.size() > 0)
	{
		_mainChain[0] = _pairs[0].second;
		for (unsigned long i = 1; i <= _pairs.size(); ++i)
		{
			_mainChain[i] = _pairs[i - 1].first;
			if (i < _pairs.size())
			{
				_pend[i - 1] = _pairs[i].second;
			}
		}
	}
}

std::vector<int>::iterator	PmergeMe::findPositionInMain(const int &i)
{
	std::vector<int>::iterator it = _mainChain.begin();

	while (it != _mainChain.end() && *it < i)
		++it;

	return (it);
}

void PmergeMe::insertSort()
{
	std::vector<int>::iterator positionInMain;

	// Loop through the insertion sequence
	for (std::vector<int>::iterator it = _insertionSequence.begin(); it != _insertionSequence.end(); ++it)
	{
		int index = *it - 2;

		// Ensure the index is valid and within bounds
		if (index >= 0 && index < static_cast<int>(_pend.size()))
		{
			positionInMain = findPositionInMain(_pend[index]);
			_mainChain.insert(positionInMain, _pend[index]);
		}
	}

	// Ensure all elements in _pend are inserted into _mainChain
	for (size_t i = 0; i < _pend.size(); ++i)
	{
		if (std::find(_insertionSequence.begin(), _insertionSequence.end(), i + 2) == _insertionSequence.end())
		{
			positionInMain = findPositionInMain(_pend[i]);
			_mainChain.insert(positionInMain, _pend[i]);
		}
	}
	// Insert _oddNum if it's non-negative
	if (_oddNum >= 0)
	{
		positionInMain = findPositionInMain(_oddNum);
		_mainChain.insert(positionInMain, _oddNum);
	}
}

void PmergeMe::mergeInsertSort()
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
		std::vector<int> mainChain(1, _oddNum);
	_mainChain = mainChain;
	}
	_endTime = clock();
}

void PmergeMe::getTime(void) const
{
	double _duration = double(_endTime - _startTime) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " <<  _duration * 1000 << " us" << std::endl;
}
