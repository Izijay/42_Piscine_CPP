/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:42:41 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/06 15:27:28 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <time.h>
#include "stdlib.h"


void    randInt(int &nbr) {

    nbr = rand() % 1000;
}

void    randChar(char &c) {

    c = 'a' + rand() % 26;
}

void    stringReplace(std::string &str)
{
    str = "42 for life !";
    return ;
}

int main(int, char**)
{
    srand(time(0));

    std::cout << "\t\t--- INT tests: ---" << std::endl;
    unsigned int size(10);
    Array <int>testInt(size);

    std::cout << testInt;
    iter<int>(testInt, randInt);
    std::cout << std::endl;
    std::cout << testInt;

    std::cout << "\n\t\t--- CHAR tests: ---" << std::endl;
    size = 8;
    Array<char>testChar(size);

    std::cout << testChar;
    iter<char>(testChar, randChar);
    std::cout << std::endl;
    std::cout << testChar;

    std::cout << std::endl;

    std::cout << "\t\t--- STRING tests: ---" << std::endl;
    Array<std::string>strs(5);
    std::cout << strs;
    iter<std::string>(strs, stringReplace);
    std::cout << strs;
    std::cout << std::endl;

    std::cout << "\t\t--- Empty Array test: ---" << std::endl;
    Array<int>empty;
    std::cout << "Size of empty array: " << empty.size() << std::endl;

    std::cout << std::endl;

    std::cout << "\t\t--- Test range exception: ---" << std::endl;
    try {
        testChar[-2];
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	   try {
        testChar[10];
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl << std::endl;

    return (0);
}