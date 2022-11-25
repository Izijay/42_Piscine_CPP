/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:35:07 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/12 13:14:08 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Here we allocate on stack because the randomZombie announces himself only 
// in that function. So we don't need to delete it.

void	randomChump(std::string name)
{
	Zombie	randomZombie(name);
	randomZombie.announce();
	return;
}
