/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:58:37 by soren             #+#    #+#             */
/*   Updated: 2025/01/10 15:24:15 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Merz("Friedrich Merz", 200);
		std::cout << Merz << " checked into the Bundestag!" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat Scholz("Olaf Scholz", 1);
	std::cout << Scholz << " checked into the Bundestag!" << std::endl;
	try
	{
		Scholz.decrementGrade();
		std::cout << "Scholz after decrement:\n" << Scholz << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat Lindner("Christian Lindner", 150);
	std::cout << Lindner << " checked into the Bundestag!" << std::endl;

	ShrubberyCreationForm	Shrub("Shrubbery_file");
	RobotomyRequestForm		Robo("Testsubject");
	PresidentialPardonForm	Pardon("You");

	Lindner.signForm(Shrub);
	Scholz.signForm(Shrub);
	Lindner.executeForm(Shrub);
	Scholz.executeForm(Shrub);
	Scholz.signForm(Robo);
	Scholz.executeForm(Robo);
	Scholz.signForm(Pardon);
	Scholz.executeForm(Pardon);
}
