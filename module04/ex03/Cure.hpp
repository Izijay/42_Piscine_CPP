/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:40:06 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 10:25:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "Character.hpp"
# include <iostream>

class 	Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &src);
		virtual ~Cure();

		Cure		&operator=(Cure const &rhs);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif // CURE.HPP