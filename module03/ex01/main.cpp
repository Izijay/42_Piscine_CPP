/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:18:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/22 13:55:54 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main( void )
{
	ClapTrap	clap("ClapTrap1");
	ScavTrap	scav("ScavTrap1");

	std::cout << std::endl;
	clap.attack("Jean-Louis");
	clap.takeDamage(7);
	clap.beRepaired(5);
	scav.attack("Phillipe");
	scav.takeDamage(2);
	scav.beRepaired(3);
	clap.attack("Jean-Louis");
	scav.attack("Paul");
	scav.takeDamage(40);
	scav.beRepaired(15);
	scav.guardGate();
	std::cout << std::endl;
	return (0);
}