/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:19:42 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/12 13:47:38 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		std::string	getName(void) const;
		void		setName(std::string name);
		void		announce(void) const ;

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
