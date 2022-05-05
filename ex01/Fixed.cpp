/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/04 15:23:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fpnum(10)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _fpnum = num << bits;
}

Fixed::Fixed( const float fnum)
{
    std::cout << "Float constructor called" << std::endl;
    _fpnum = static_cast<int>(roundf(fnum * Fixed::convert_bits(bits)));
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fpnum = copy._fpnum;
}

Fixed Fixed::operator=(const Fixed &fixed){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed)
        return *this;
    _fpnum = fixed._fpnum;
    return *this;
}

void Fixed::setRawBits( int const raw ){
    _fpnum = raw;
}

int Fixed::getRawBits( void ) const{
    return _fpnum;
}

int Fixed::convert_bits(const int bits) {
    int value;

    value = 1;
    if (bits == 0)
        return 1;
    for (int num = 0; num < bits; num++)
        value = value * 2;
    return value;
}

int Fixed::toInt( void ) const{
    return _fpnum >> bits;
}

float Fixed::toFloat( void ) const {
    return  static_cast<float>(_fpnum) / Fixed::convert_bits(bits);
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}