/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:37:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/06 15:15:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BasicTemplate.hpp"

// Subject's main:

/* class 	Awesome {
	public:
		Awesome(void) : _n(0) {}
		Awesome(int n) : _n(n) {}
		Awesome & operator=(Awesome const &rhs) {_n = rhs._n; return (*this); }
		bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
		bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
		bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
		bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
		bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
		bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
		int getN(void) const { return (this->_n); }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream &o, Awesome const &rhs) {
	o << rhs.getN();
	return (o);
}

int main(void) {
	Awesome a(2), b(4);
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << min(a, b) << std::endl << max(a, b) << std::endl;
	return (0);
} */


// My main :

int	main(void)
{
	int a = 42;
	int b = 21;

	std::cout << "a =\t" << a;
	std::cout << "\nb =\t" << b << std::endl;
	swap(a, b);
	std::cout << "swap( a, b ):" << std::endl;
	std::cout << "a =\t" << a << std::endl << "b =\t" << b << std::endl;
	std::cout << "min( a, b ) =\t" << min(a, b) << std::endl;
	std::cout << "max( a, b ) =\t" << max(a, b) << std::endl << std::endl;
	// -------------------------------------------------------------------------
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "c = " << c ;
	std::cout << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "swap( c, d ): " << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;
	// -------------------------------------------------------------------------
	char e = 'e';
	char f = 'f';
	std::cout << "e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "swap( e, f ): " << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	return (0);
}