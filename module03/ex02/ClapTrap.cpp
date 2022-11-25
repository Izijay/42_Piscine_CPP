/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:09:06 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/22 13:54:55 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("DEFAULT"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10)
{
	std::cout << "ClapTrap constructor called --- ";
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called --- ";
	std::cout << "ClapTrap " << this->_name << " created" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (target.size() < 1 )
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack target with no name" << std::endl;
		return ;
	}
	if (this->_energyPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot attack (out of energy points)" << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "ClapTrap " << this->_name << " cannot attack (out of hit points)" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " for " << this->_attackDamage << " damages." << std::endl;
		this->_energyPoints -= 1;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	long long int tmp;
	
	tmp = this->_hitPoints;
	if (amount < 1) {
		std::cout << "ClapTrap " << this->_name << " cannot be attacked with 0 or less points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage point(s) -- ";
	if (tmp - amount < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " have " << this->_hitPoints << " hit points left" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (amount < 1 || amount > 1000000) {
		std::cout << "ClapTrap " << this->_name << " cannot be repaired with 0 or less points" << std::endl;
		return ;
	}
	if (this->_energyPoints < 1)
		std::cout << "ClapTrap" << this->_name << " cannot be repaired (out of energy)" << std::endl;
	else if (this->_hitPoints < 1)
		std::cout << "ClapTrap" << this->_name << " cannot be repaired (is already dead)" << std::endl;
	else {
		std::cout << "ClapTrap " << this->_name << " be repaired for " << amount << " Hit Points -- ";
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		if (this->_hitPoints > this->_maxHitPoints) {
			this->_hitPoints = this->_maxHitPoints;
			std::cout << "Maximum hit points reached -- ";
		}
		std::cout << this->_name << " have " << this->_hitPoints << " hit points left" << std::endl; 
	}
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}