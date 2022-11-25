/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:05:26 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/08 11:27:23 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>


template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(MutantStack const &src) {*this = src;}
		~MutantStack(){}
		MutantStack &operator=(MutantStack const &rhs)	{
			this->c = rhs.c;
			return (*this);
		}
		
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { 
        
        return (this->c.begin());
    }
	
    iterator end() {
        return (this->c.end());
    }
};