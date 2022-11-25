/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:29:40 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 12:59:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called --- DiamondTrap " << this->_name << " constructed" << std::endl;
	this->_name = "DEFAULT";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap constructor called --- DiamondTrap " << this->_name << " constructed" << std::endl;
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called -- DiamondTrap "  << src._name << " constructed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	ClapTrap::operator=(rhs);
	ScavTrap();
	FragTrap();
	return *this;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap\'s whoAmI() called -- ";
	std::cout << "I am " << this->_name << " and you can call me " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called --- DiamondTrap " << this->_name << " destructed" << std::endl;
}