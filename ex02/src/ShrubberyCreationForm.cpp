/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:52:26 by stopp             #+#    #+#             */
/*   Updated: 2025/01/10 15:18:07 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137, false, "")
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137, false, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{

}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return (*this);
}

void	ShrubberyCreationForm::execute_action() const
{
	std::ofstream	outFile(getTarget().c_str());
	if (!outFile.is_open())
		return;
	outFile << "     /\\ " << std::endl;
	outFile << "    / *\\ " << std::endl;
	outFile << "   /*   \\ " << std::endl;
	outFile << "  /     *\\ " << std::endl;
	outFile << " / *   *  \\ " << std::endl;
	outFile << "/---|  |---\\ " << std::endl;
	outFile << "    |  |   " << std::endl;
	outFile.close();
}
