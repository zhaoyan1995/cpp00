/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:18 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/20 14:24:49 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	cmd;

	while (1)
	{
		std::cout << CYAN << "Please enter a command (ADD/SEARCH/EXIT):" << RESET << std::endl;
		if (!std::getline(std::cin, cmd))
	    		break ;
		if (cmd == "ADD")
		{
		    if (!phone_book.addContact())
			break ;
		}
		else if (cmd == "SEARCH")
		{
		    if (!phone_book.searchContact())
			break ;
		}
		else if (cmd == "EXIT")
		    break ;
		else
		    std::cerr << RED << "The input is an invalid command!" << RESET << std::endl;
	}
	std::cout << "Bye!" << std::endl;
	return (0);
}
