/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:18 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/15 23:34:48 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
    //std::cout << "A Contact instance has been created." << std::endl;
    return ;
}

Contact::~Contact(void)
{
    //std::cout << "A Contact instance has been destroyed." << std::endl;
    return ;
}

void    Contact::set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    this->_first_name = fn;
    this->_last_name = ln;
    this->_nick_name = nn;
    this->_phone_number = pn;
    this->_darkest_secret = ds;
    return ;
}

std::string Contact::_format_helper(std::string input)const
{
    size_t  i;

    i = 0;
    while (i < input.length())
    {
        if (std::isspace(input[i]))
            input[i] = ' ';
        i++;
    }
    if (input.length() <= 10)
        return (input);
    else
        return (input.substr(0, 9) + ".");
}

void    Contact::display_summary(int index)const
{
    std::cout << "|";
    std::cout << std::setw(10) << index;
    std::cout << "|";
    std::cout << std::setw(10) << this->_format_helper(this->_first_name);
    std::cout << "|";
    std::cout << std::setw(10) << this->_format_helper(this->_last_name);
    std::cout << "|";
    std::cout << std::setw(10) << this->_format_helper(this->_nick_name);
    std::cout << "|" << std::endl;
    return ;
}

void    Contact::display_details(void)const
{
    std::cout << "First name: " << this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nick name: " << this->_nick_name << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
    return ;
}
