#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractBits = 8;
public:
	Fixed( void );
	Fixed( const int Integer);
	Fixed( const float Float);
	Fixed( const Fixed& copy );
	Fixed& operator=( const Fixed& copy );
	~Fixed();
	void	setRawBits( const int raw );
	int	getRawBits( void ) const;
	float	toFloat( void ) const;
	int	toInt( void ) const;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif

