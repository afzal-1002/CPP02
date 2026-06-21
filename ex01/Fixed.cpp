#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = num << (1 << fractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "float constructor called" << std::endl;
	this->num = roundf(num * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->num = other.num;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	std::cout << "This" << this << std::endl;
	if (this != &other)
		this->num = other.num;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getNum(void) const
{
	return (this->num);
}
void Fixed::setNum(int const num)
{
	this->num = num;
}
float Fixed::toFloat(void) const
{
	return ((float)this->num / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->num / (1 << fractionalBits));
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}