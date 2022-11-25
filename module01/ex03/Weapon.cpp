/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:05:52 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/12 15:36:39 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon " << _type << " created" << std::endl;
}

Weapon::~Weapon(){

}

void		Weapon::setType(std::string type){
	_type = type;
}

std::string const &Weapon::getType()
{
	return _type;
}