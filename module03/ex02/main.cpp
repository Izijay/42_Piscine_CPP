/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:18:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/22 09:56:41 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main( void )
{
	ScavTrap	scav("ScavTrap1");
	FragTrap	frag("FragTrap1");

	std::cout << std::endl;
	scav.attack("Jean-Louis");
	scav.takeDamage(20);
	scav.beRepaired(15);
	frag.attack("Paul");
	frag.takeDamage(40);
	scav.guardGate();
	scav.attack("Jean-Louis");
	scav.takeDamage(7);
	frag.beRepaired(20);
	frag.highFivesGuys();
	scav.attack("Jean-Louis");
	frag.attack("Paul");
	std::cout << std::endl;
	return (0);
}