/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:33:36 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 15:52:35 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
class 	Array {

	public:
		Array( void ) : _size(0), _tab(NULL) {
			std::cout << "Array( void ) constructor called" << std::endl;
		}
		Array( unsigned int n ) : _size(n), _tab(new T[n]()) {
			std::cout << "Array( unsigned int n ) constructor called" << std::endl;
		}
		Array(Array const &src) {
			std::cout << "Array Copy constructor called" << std::endl;
			this->_size = src._size;
			this->_tab = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_tab[i] = src._tab[i];
		}
		~Array( void ) {
			std::cout << "Array destructor called" << std::endl;
			delete [] this->_tab;
		}

		Array	&operator=(Array const &rhs) {
			std::cout << "Array operator assignation called" << std::endl;
			if (this != &rhs) {
				delete [] this->_tab;
				this->_size = rhs._size;
				this->_tab = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_tab[i] = rhs._tab[i];
			}
			return *this;
		}

		T	&operator[](unsigned const int &i) const {
			if (i >= this->_size)
				throw (std::runtime_error("error: exception: Index out of range"));
			return this->_tab[i];
		}

		unsigned int	size( void ) const {
			return this->_size;
		}

	private:
		unsigned int	_size;
		T				*_tab;
};

template<typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &rhs) {
	o << "\tArray<T> : " << std::endl;
	for (unsigned int i = 0; i < rhs.size(); i++)
		o << "tab[ " << i << " ]  ->\t" << rhs[i] << std::endl;
	return o;
}

template<typename T>
void	iter(Array<T> &arr, void (*f)(T &)) {
	for (unsigned int i = 0; i < arr.size(); i++)
		f(arr[i]);
}