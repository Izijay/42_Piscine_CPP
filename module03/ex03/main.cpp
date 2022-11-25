/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:18:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/22 10:05:05 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int		main( void )
{
	DiamondTrap	dia("DiamondTrap1");

	std::cout << std::endl;
	dia.takeDamage(95);
	dia.beRepaired(5);
	dia.takeDamage(10);
	dia.attack("Jean-Louis");
	dia.guardGate();
	dia.highFivesGuys();
	dia.whoAmI();
	std::cout << std::endl;
	return (0);
}
