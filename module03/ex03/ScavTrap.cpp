/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:12:53 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 13:17:01 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_maxHitPoints = 100;
	std::cout << "ScavTrap constructor called --- ScavTrap " << this->_name << " is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_maxHitPoints = 100;
	std::cout << "ScavTrap constructor called --- ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " : Gate kepper mode activated." << std::endl;
}

void	ScavTrap::attack(std::string const &target) {
	
	if (target.size() < 1 )
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack target with no name" << std::endl;
		return ;
	}
	if (this->_energyPoints < 1)
		std::cout << "ScavTrap " << _name << " cannot attack (out of energy points)" << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "ScavTrap " << _name << " cannot attack (out of hit points)" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " for " << this->_attackDamage << " damages." << std::endl;
		this->_energyPoints -= 1;
	}
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called --- ";
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}