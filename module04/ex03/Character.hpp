/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:29:43 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 10:25:04 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class 	Character : public ICharacter {
	
	public :
			Character();
			Character(std::string name);
			Character(Character const &src);
			~Character();
			
			Character &operator=(Character const &rhs);

			const std::string 	&getName( void ) const;
			AMateria			*getInventory( int idx ) const;
			void				equip(AMateria *m);
			void				unequip(int idx);
			void				use(int idx, ICharacter &target);


	protected:
			std::string _name;
			AMateria	**_inventory;
};

#endif // CHARACTER_H