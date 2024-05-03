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
	~Fixed();

	Fixed&	operator=( const Fixed& copy );

	bool	operator<( const Fixed& copy ) const;
	bool	operator>( const Fixed& copy ) const;
	bool	operator<=( const Fixed& copy ) const;
	bool	operator>=( const Fixed& copy ) const;
	bool	operator==( const Fixed& copy ) const;
	bool	operator!=( const Fixed& copy ) const;

	Fixed	operator+( const Fixed& copy ) const;
	Fixed	operator-( const Fixed& copy ) const;
	Fixed	operator*( const Fixed& copy ) const;
	Fixed	operator/( const Fixed& copy ) const;

	Fixed	operator++( void );
	Fixed	operator--( void );
	Fixed	operator++(int	Placeholder);
	Fixed	operator--(int	Placeholder);

	static Fixed&		min( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static Fixed&		max( Fixed& a, Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );

	void	setRawBits( const int raw );
	int	getRawBits( void ) const;

	float	toFloat( void ) const;
	int	toInt( void ) const;
};

std::ostream& operator<<( std::ostream& o, Fixed const& i );

#endif
