/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:46:26 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/22 09:54:07 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "FragTrap constructor called --- FragTrap " << this->_name << " is created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_maxHitPoints = 100;
	std::cout << "FragTrap constructor called --- FragTrap " << this->_name << " is created" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy" << this->_name << " is created" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(std::string const &target)
{
	
	if (target.size() < 1 )
	{
		std::cout << "FragTrap " << this->_name << " cannot attack target with no name" << std::endl;
		return ;
	}
	if (this->_energyPoints < 1)
		std::cout << "FragTrap " << _name << " cannot attack (out of energy points)" << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "FragTrap " << _name << " cannot attack (out of hit points)" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " for " << this->_attackDamage << " damages." << std::endl;
		this->_energyPoints -= 1;
	}
	return ;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " wanna High Fives !" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called --- ";
	std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}