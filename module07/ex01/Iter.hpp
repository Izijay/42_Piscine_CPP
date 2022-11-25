/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:06:13 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/06 11:25:46 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	fctn(T &arg)
{
	arg = 42;
	return ;
}

template<typename T>
void	iter(T *tabAdd, size_t size, void (*fctn)(T &))
{
	for (size_t i = 0; i < size; i++)
		fctn(tabAdd[i]);
	return ;
}