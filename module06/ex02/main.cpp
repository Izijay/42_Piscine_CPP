/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:57:16 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 13:25:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

Base	*generate(void)
{
	int nb = rand() % 3;
	if (nb == 0)
		return (new A);
	else if (nb == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	A *a;
	B *b;
	C *c;
	
	if ((a = dynamic_cast<A *>(p)) != NULL)
		std::cout << "A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)) != NULL)
		std::cout << "B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
	}
	
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {
	}
	
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {
	}
}

int main(void)
{
	Base	*p;
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		p = generate();
		std::cout << "identify by ptr :\t";
		identify(p);
		std::cout << "identify by ref :\t";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
	return (0);
}