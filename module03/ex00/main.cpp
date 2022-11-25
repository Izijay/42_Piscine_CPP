/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:18:12 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/17 10:18:50 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main( void )
{
	ClapTrap	robert("Robert");

	std::cout << std::endl;
	robert.attack("");
	robert.attack("Jean-Louis");
	robert.takeDamage(7);
	robert.takeDamage(0);
	robert.takeDamage(-42);
	robert.beRepaired(5);
	robert.beRepaired(0);
	robert.attack("Paul");
	robert.beRepaired(-42);
	robert.attack("Phillipe");
	robert.takeDamage(2);
	robert.beRepaired(3);
	robert.beRepaired(100);
	robert.attack("Jean-Louis");
	robert.attack("Paul");
	robert.takeDamage(7);
	robert.beRepaired(5);
	robert.attack("Jean-Louis");
	robert.attack("Paul");
	std::cout << std::endl;
	return (0);
}