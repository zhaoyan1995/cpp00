/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:12 by yanzhao           #+#    #+#             */
/*   Updated: 2026/01/15 22:47:33 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void display_summary(int index)const;
		void display_details(void)const;

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _darkest_secret;
		std::string _format_helper(std::string input)const;

};

#endif