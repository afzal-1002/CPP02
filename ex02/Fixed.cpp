/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:55:52 by mafzal            #+#    #+#             */
/*   Updated: 2026/06/23 01:56:08 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->num = 0;
}

Fixed::Fixed(const int num)
{
	this->num = num << fractionalBits;
}
Fixed::Fixed(const float num)
{
	this->num = roundf(num * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->num = other.num;
	return (*this);
}

Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
	return (this->num);
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->num / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->num >> fractionalBits);
}

// Comparison Operators

bool Fixed::operator>(const Fixed &other) const
{
	return (this->num > other.num);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->num < other.num);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->num >= other.num);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->num <= other.num);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->num == other.num);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->num != other.num);
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->num + other.num);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->num - other.num);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->num * other.num) / (1 << fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->num * (1 << fractionalBits)) / other.num);
	return (result);
}

Fixed &Fixed::operator++()
{
	this->num++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->num++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->num--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->num--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}