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
	const std::string sample[] = {
		"Pet me",
		"Eat Food",
		"Sleep",
		"Play",
		"Drink Water"
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = sample[i % 5];
	std::cout << "Brain() constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
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