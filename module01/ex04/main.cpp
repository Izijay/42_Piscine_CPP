/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:07:59 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/15 13:23:31 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

static void		myReplace(std::string &line, std::string const &toReplace, std::string const &replaceBy)
{
	std::string::size_type pos;
	std::string::size_type start = 0;
	while ((pos = line.find(toReplace, start)) != std::string::npos)
	{
		line.erase(pos, toReplace.length());
		line.insert(pos, replaceBy);
		start = pos + replaceBy.length();
	}
	return;
}

int	main(int ac, char **av)
{
	if (ac != 4 && (!av[1] || !av[2] || !av[3])) 
	{
		std::cout << "error: replace: bad arguments." << std::endl \
			<< "Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	else
	{
		std::string file = av[1];
		std::string str1 = av[2];
		std::string str2 = av[3];
		std::string line;
	
		if (file.size() == 0 || str1.size() == 0 || str2.size() == 0){
			std::cout << "error: bad input" << std::endl;
			return (1);
		}
		std::ifstream ifile(file.data());
		if (ifile.fail())
		{
			std::cout << "error: replace: cannot open input file " << file << std::endl;
			return (1);
		}
		
		std::ofstream ofile(file.append(".replace").data());
		if (ofile.fail())
		{
			std::cout << "error: replace: cannot create output file " << file << std::endl;
			return (1);
		}
		
		while (std::getline(ifile, line))
		{
			if (ifile.fail())
				return (0);
			myReplace(line, str1, str2);
			ofile << line << std::endl;
			line.clear();		
		}
		ifile.close();
		ofile.close();
	}
	return (0);
}
