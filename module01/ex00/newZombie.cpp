/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:33:53 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/12 13:16:47 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Here we allocate on heap because the *zombie is returned by the function and 
//became not only a locale "variable". So we need to delete it mannually in main().

Zombie		*newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}
