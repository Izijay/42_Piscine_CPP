/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
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

class 	AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string name);
		AAnimal(AAnimal const &src);
		AAnimal& operator=(AAnimal const &rhs);
		virtual ~AAnimal();

		std::string getType( void ) const;

		virtual void	makeSound( void ) const = 0;
	
	protected:
		std::string _type;
};

#endif // ANIMAL_HPP