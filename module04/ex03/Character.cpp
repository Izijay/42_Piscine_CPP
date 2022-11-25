/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:38:48 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 15:14:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _inventory(new AMateria*[4]())
{
	std::cout << "Character() constructor called" << std::endl;
	this->_name = "DEFAULT";
	return ;
}

Character::Character(std::string name) : _name(name), _inventory(new AMateria*[4]())
{
	std::cout << "Character( name ) Constructor called --- " << this->_name << " created." << std::endl;
	return ; 
}

Character::Character(Character const &src)
{
	std::cout << "Character copy Constructor called" << std::endl;
	this->_inventory = new AMateria*[4]();
	*this = src;
}

Character	&Character::operator=(Character const &rhs)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		if (this->_inventory)
		{
			for (int i = 0; i < 4; i++)
				delete this->_inventory[i];
			delete [] this->_inventory;
		}
		AMateria **tmp = new AMateria*[4];
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i])
				tmp[i] = rhs._inventory[i]->clone();
			else
				tmp[i] = NULL;
		}
		this->_inventory = tmp;
	}
	
	return (*this);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	int i = 0;
	while (this->_inventory[i] != NULL) {
		if (!this->_inventory[i])
			break ;
		i++;
	}
	if (i == 3 && this->_inventory[i] != NULL) {
		std::cout << "Inventory is full" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (this->_inventory[idx] && idx >= 0 && idx <= 3) {
		this->_inventory[idx] = NULL;
		std::cout << "Unequipped #" << idx << " slot of " << this->_name << std::endl;
	}
	else
		std::cout << "No item in #" << idx << " slot of " << this->_name << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	AMateria *tmp = this->_inventory[idx];
	if (tmp && (tmp->getType() == "ice" || tmp->getType() == "cure")) {
		tmp->use(target);
		std::cout << this->_name << " used " << this->_inventory[idx]->getType() << " on " << target.getName() << std::endl;
	}
	else {
		std::cout << "No item in #" << idx << " slot of " << this->_name << std::endl;
		delete tmp;
	}
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

AMateria	*Character::getInventory(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (this->_inventory[idx]);
}

Character::~Character() {
	std::cout << "Character Destructor called -- " << this->_name << " deleted" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	delete [] (_inventory);
}