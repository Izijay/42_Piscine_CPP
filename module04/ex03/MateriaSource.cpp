/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:03:49 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 15:19:57 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 4; i++)
			this->_materia[i] = rhs._materia[i];
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m->getType() == "ice")
	{
		AMateria *tmp = new Ice();
		int i = 0;
		while (this->_materia[i] != NULL)
			i++;
		if (i == 3) {
			std::cout << "Inventory is full" << std::endl;
			return; 
		}
		this->_materia[i] = tmp;	
	}
	else if (m->getType() == "cure")
	{
		AMateria *tmp = new Cure();
		int i = 0;
		while (this->_materia[i] != NULL)
			i++;
		if (i == 3) {
			std::cout << "Inventory is full" << std::endl;
			return; 
		}
		this->_materia[i] = tmp;	
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (this->_materia[i] != NULL) {
		if (!this->_materia[i]->getType().compare(type))
			return this->_materia[i];
		i++;
	}
	return NULL;
}


MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	
}