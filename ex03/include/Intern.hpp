/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:44:46 by stopp             #+#    #+#             */
/*   Updated: 2025/01/10 16:26:39 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class	Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &copy);

		AForm	*makeForm(std::string formName, std::string target);
};
