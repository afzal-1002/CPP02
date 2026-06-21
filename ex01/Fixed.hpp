#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int rawBits;
	int num;

  public:
	Fixed();
	Fixed(const int num);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int getNum(void) const;
	void setNum(int const num);
	float toFloat( void ) const;
};

#endif