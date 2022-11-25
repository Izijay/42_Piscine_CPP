/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:23 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 16:40:23 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain() constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
		std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	return (*this);
}

void				Brain::setIdea(int i, std::string &idea)
{
	this->_ideas[i] = idea;
}

const std::string	&Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
}