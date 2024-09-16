#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <iterator>
# include <deque>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack( void );
		MutantStack( const MutantStack& copy );
		MutantStack<T>& operator=( const MutantStack& copy );
		~MutantStack( void );

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
