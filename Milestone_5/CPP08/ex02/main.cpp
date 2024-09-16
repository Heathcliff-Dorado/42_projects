#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		//push ->adds member
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		//pop->remove member
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
	MutantStack<int> mstack;
	std::stack<int> mirror;
	std::cout << "\033[35m--Testing empty stack behavior--\033[0m" << std::endl;
	std::cout << "Empty stack size: " << mstack.size() << std::endl;
	std::cout << "Is empty stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(9);
	mstack.push(737);
	std::cout << "\e[0;103mMutantStack top: \e[0m" << mstack.top() << std::endl;
	std::cout << "\e[0;103mMutantStack size: \e[0m" << mstack.size() << std::endl;

	mirror.push(5);
	mirror.push(17);
	mirror.push(3);
	mirror.push(9);
	mirror.push(737);
	std::cout << "Normal stack top: " << mirror.top() << std::endl;
	std::cout << "Normal stack size: " << mirror.size() << std::endl;

	std::cout << std::endl;

	std::cout << "\033[35m--Testing copy constructor and assignment operator:--\033[0m" << std::endl;
	MutantStack<int> copiedStack(mstack);
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "\e[0;103mCopied stack top: \e[0m" << copiedStack.top() << std::endl;
	std::cout << "\e[0;103mAssigned stack top: \e[0m" << assignedStack.top() << std::endl;

	std::cout << std::endl;

	std::cout << "\033[35m--Testing iterators:--\033[0m" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\033[35m--Testing reverse iterators:\033[0m" << std::endl;
	MutantStack<int>::reverse_iterator rIter = mstack.rbegin();
	MutantStack<int>::reverse_iterator rIterEnd = mstack.rend();
	while (rIter != rIterEnd)
	{
		std::cout << *rIter << std::endl;
		++rIter;
	}

	std::cout << std::endl;

	std::cout << "--\033[35mTesting conversion to std::stack:\033[0m" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "MutantStack: " << std::endl;
	while (!mstack.empty())
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}
	std::cout << "\e[0;103mconverted to std::stack: \e[0m" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\n\033[35m--Testing push and pop operations with chars:\033[0m" << std::endl;
	MutantStack<char> charStack;
	charStack.push('a');
	charStack.push('b');
	charStack.push('c');
	std::cout << "Top after pushes: " << charStack.top() << std::endl;
	charStack.pop();
	std::cout << "Top after one pop: " << charStack.top() << std::endl;
	charStack.push('d');
	std::cout << "Top after push 'd': " << charStack.top() << std::endl;

	std::cout << "\n\033[35m--Testing iterators with strings:\033[0m" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("hello");
	strStack.push("world");
	strStack.push("!");
	MutantStack<std::string>::iterator iter = strStack.begin();
	MutantStack<std::string>::iterator iterEnd = strStack.end();
	while (iter != iterEnd)
	{
		std::cout << *iter << " ";
		++iter;
	}

	std::cout << std::endl;
	}
	return 0;
}
