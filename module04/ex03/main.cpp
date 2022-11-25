/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:57:29 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 16:13:06 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* mage = new Character("Big Mage");
	ICharacter* tank = new Character("Big Tank");
	AMateria* tmp;
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	mage->equip(tmp);
	tmp = src->createMateria("cure");
	mage->equip(tmp);
	tmp = src->createMateria("ice");
	mage->equip(tmp);
	tmp = src->createMateria("cure");
	mage->equip(tmp);
	tmp = src->createMateria("ice");
	mage->equip(tmp);
	mage->unequip(0);
	tmp = src->createMateria("cure");
	mage->equip(tmp);
	mage->use(0, *tank);
	mage->use(3, *tank);
	std::cout << std::endl;

	std :: cout << "===========================================================================================" << std::endl;
	std::cout << std::endl;

	//ICharacter *player(mage);
	//ICharacter *enemy(tank);
	AMateria* tmp2 = tmp ;

	mage->unequip(1);
	tmp2 = src->createMateria("ice");
	mage->equip(tmp2);
	mage->unequip(3);
	tmp2->clone();
	mage->equip(tmp2);
	mage->use(3, *tank);
	mage->use(0, *tank);
	mage->use(0, *tank);
	mage->use(1, *tank);

	//tmp = src->createMateria("ice");
	//tank->equip(tmp);
	//tank->use(0, *mage);

	std::cout << std::endl;
	//delete player;
	//delete enemy;
	delete tank;
	delete mage;
	delete src;

	return 0;
} */

int main()
{
	// Subject's main :
	{
		std::cout << "\t\t\t ** Subject's main : **" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << std::endl;
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl << "***-----------------------------------------------------------***" << std::endl << std::endl;
	{
		std::cout << "\t\t\t ** My main : **" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* bigMage = new Character("Big Mage");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		bigMage->equip(tmp);
		tmp = src->createMateria("cure");
		bigMage->equip(tmp);

		Character* betterOne = new Character("Better One");

		std::cout << "**---------------**" << std::endl;
		std::cout << std::endl << "\t ** Copy Constructor : **" << std::endl;
		Character *bigMageCopy = new Character(*bigMage);
		Character *betterOneCopy = new Character(*betterOne);
		std::cout << "**---------------**" << std::endl << std::endl;
		std::cout << "Original Big Mage cast: " << std::endl;
		bigMage->use(0, *betterOne);
		bigMage->use(1, *betterOne);

		std::cout << std::endl <<  "**---------------**" << std::endl << std::endl;
		std::cout << "Copy Big Mage cast: " << std::endl;
		bigMageCopy->use(0, *betterOneCopy);
		bigMageCopy->use(1, *betterOneCopy);

		std::cout << std::endl << "**---------------**" << std::endl;
		std::cout << std::endl << "\t ** Unequip test : **" << std::endl;

		AMateria *materiaCopy = bigMageCopy->getInventory(1);
		std::cout << "Unequip slot #1 of Big Mage Copy: " << std::endl;
		bigMageCopy->unequip(1);
		std::cout << "Big mage copy cast : " << std::endl;
		bigMageCopy->use(0, *betterOneCopy);
		bigMageCopy->use(1, *betterOneCopy);
		std::cout << "Original Big Mage cast : " << std::endl;
		bigMage->use(0, *betterOne);
		bigMage->use(1, *betterOne);
		std::cout << std::endl << "**---------------**" << std::endl;

		delete src;
		delete betterOne;
		delete betterOneCopy;
		delete bigMage;
		delete bigMageCopy;
		delete materiaCopy;
	}
	return 0;
}