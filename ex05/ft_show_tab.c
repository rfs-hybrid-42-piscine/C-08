/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:28:59 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 02:34:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

/**
 * @fn static void ft_putstr(char *str)
 * @brief Prints a null-terminated string to the standard output.
 * @details Includes a safety check to prevent dereferencing a NULL pointer.
 * Uses pointer arithmetic to iterate through the memory addresses, writing 
 * each character to file descriptor 1 until the null byte is reached.
 * @param str A pointer to the first character of the string to be printed.
 */
static void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

/**
 * @fn static void ft_putnbr(int nb)
 * @brief Prints any valid integer to the standard output.
 * @details Casts the absolute value to an unsigned int to safely prevent
 * integer overflow from INT_MIN. Uses recursive division to isolate digits.
 * @param nb The integer to print.
 */
static void	ft_putnbr(int nb)
{
	unsigned int	n;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(-nb);
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

/**
 * @fn void ft_show_tab(struct s_stock_str *par)
 * @brief Displays the formatted content of a structure array.
 * @details Iterates through the array until the null-terminator is reached.
 * For each structure, prints the string, the size, and the copy, each 
 * followed strictly by a newline character.
 * @param par A pointer to the dynamically allocated array of structures.
 */
void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
		write (1, "\n", 1);
	}
}
