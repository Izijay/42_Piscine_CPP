/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:38:28 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 10:25:18 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "Character.hpp"
# include "AMateria.hpp"
# include <iostream>

class 	Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & src);
		virtual ~Ice();

		Ice		&operator=(Ice const & rhs);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif //ICE_HPP