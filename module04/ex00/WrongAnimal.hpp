/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:38:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 15:38:37 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class 	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal& operator=(WrongAnimal const &rhs);
		virtual ~WrongAnimal();

		std::string getType( void ) const;

		void	makeSound( void ) const;
	
	protected:
		std::string _type;
};

#endif // WRONGANIMAL_HPP