/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:33:30 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:33:30 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class 	Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(Animal const &src);
		Animal& operator=(Animal const &rhs);
		virtual ~Animal();

		std::string getType( void ) const;

		virtual void	makeSound( void ) const;
	
	protected:
		std::string _type;
};

#endif // ANIMAL_HPP