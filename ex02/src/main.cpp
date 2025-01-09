/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soren <soren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:58:37 by soren             #+#    #+#             */
/*   Updated: 2024/12/24 13:41:48 by soren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

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
	try
	{
		Lindner.decrementGrade();
		std::cout << "Lindner after decrement:\n" << Lindner << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}


	Form a("FormA", 110, 140);
	Form b("FormB", 1, 1);

	Scholz.signForm(a);
	Scholz.signForm(b);
}
