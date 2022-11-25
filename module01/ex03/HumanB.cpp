/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:05:49 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/14 15:35:31 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack() {
	std::cout << this->_name << " attacks with ";
	if (this->_weapon != NULL)
		std::cout << "their " << this->_weapon->getType() << std::endl;
	else
		std::cout << "no weapon" << std::endl;
}

Weapon	*HumanB::getWeapon() const {
	return this->_weapon;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}