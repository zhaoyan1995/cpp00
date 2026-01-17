/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:55:31 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/10 20:13:08 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i;
	size_t	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			std::string param = argv[i];
			while (j < param.length())
			{
				std::cout << (char)std::toupper(param[j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
