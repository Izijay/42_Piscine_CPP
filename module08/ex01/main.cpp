/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:06:48 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/07 11:59:44 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

/* int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
} */

int main(void) {

    Span sp(6);
    
    std::cout << "\t\t--- longestSpan() test with empty array: ---" << std::endl; 
    try {
        sp.longestSpan();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    Span test1(50000);
    std::cout << "\t\t--- addManynumbers() test with 'b' > container's size : ---" << std::endl;
    try {
        test1.addManyNumbers(0, 100000);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    test1.addManyNumbers(2, 10000);

    std::cout << "\t\t--- shortestSpam() test: ---" << std::endl;
    try {
        std::cout << "shortestSpan's result :\t" << test1.shortestSpan() << std::endl;
    } catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "\t\t--- longestSpan() test: ---" << std::endl;
    try {
        std::cout << "longestSpan's result :\t" << test1.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    std::cout << "\t\t--- addNumber() test: ---" << std::endl;
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(666);
        std::cout << "shortestSpan's result :\t" << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan's result :\t" << sp.longestSpan() << std::endl;
        sp.addNumber(42); // Throw exception
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}