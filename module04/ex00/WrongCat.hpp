/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:25 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 15:43:25 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class 	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(WrongCat const &src);
		WrongCat& operator=(WrongCat const &rhs);
		~WrongCat();

		void		makeSound( void ) const;
};

#endif // WRONGCAT_HPP