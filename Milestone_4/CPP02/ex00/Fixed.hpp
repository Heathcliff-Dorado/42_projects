#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractBits = 8;
public:
	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed& operator=( const Fixed& copy );
	~Fixed();
	void	setRawBits( const int raw );
	int	getRawBits( void ) const;
};

#endif
