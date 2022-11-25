/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:29:50 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 17:59:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char 	*Span::EmptyContainer::what() const throw()
{
	return ("Container is empty");
}

const char	*Span::FullContainer::what() const throw()
{
	return ("Container is full");
}

Span::Span(unsigned int n) : _N(n) {
}

Span::Span(Span const &src)
{
	this->_N = src._N;
	this->_vec = src._vec;
	return ;
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_vec = rhs._vec;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_vec.size() >= this->_N) {
		throw Span::FullContainer();
		return ;
	}
	this->_vec.push_back(n);
	std::cout << "Adding " << n << " successfully !" << std::endl;
}

void	Span::addManyNumbers(int a, int b)
{
	long range;

	if (a > b) 
		range = a - b;
	else
		range = b - a;
	if (this->_vec.size() + range >= this->_N) {
		throw Span::FullContainer();
		return ;
	}
	for (long i = 0; i < range; i++) {
		this->_vec.push_back(a + i);
	}
}
	
unsigned int 	Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw Span::EmptyContainer();
	std::sort(this->_vec.begin(), this->_vec.end());
	std::vector<int>::iterator i = this->_vec.begin();
	std::vector<int>::iterator j = i + 1;

	unsigned int nb = ~0;
	while (j != this->_vec.end())
	{
		if (static_cast<unsigned int>(*j - *i) < nb)
			nb = *j - *i;
		i++;
		j++;
	}
	return (nb);
}

unsigned int 	Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw Span::EmptyContainer();
	std::vector<int>::iterator max = std::max_element(this->_vec.begin(), this->_vec.end());
	std::vector<int>::iterator min = std::min_element(this->_vec.begin(), this->_vec.end());
	return (static_cast<unsigned int>(*max - *min));
}
