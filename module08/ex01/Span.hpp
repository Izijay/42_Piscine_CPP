/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:29:54 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 17:53:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <list>

class 	Span 
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &rhs);
		void addNumber(int n);
		void addManyNumbers(int a, int b);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		class EmptyContainer : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FullContainer : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		unsigned int _N;
		std::vector<int> _vec;
};
