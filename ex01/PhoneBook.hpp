/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:12 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/17 22:11:07 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"     
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

class	PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	addContact(void);
		bool	searchContact(void)const;
	
	private:
		Contact	_contacts[8];
		int	_count;
		void	_printTableHeader(void)const;
		bool	_isValideInput(std::string &input, std::string &prompt)const;
};

#endif