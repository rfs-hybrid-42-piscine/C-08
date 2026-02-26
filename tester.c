/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:41:12 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 03:24:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX01
# define EX02
# define EX03
# define EX04
# define EX05
#endif

/* --- Headers for Macros & Structs --- */
#ifdef EX01
# include "ex01/ft_boolean.h"
#endif

#ifdef EX02
# include "ex02/ft_abs.h"
#endif

#ifdef EX03
# include "ex03/ft_point.h"
#endif

#if defined(EX04) || defined(EX05)
# include "ft_stock_str.h"
void	ft_show_tab(struct s_stock_str *par); /* Added Prototype */
#endif

/* --- Mock Functions to satisfy Header Prototypes --- */
#ifdef EX01
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}
#endif

#ifdef EX03
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
#endif

/* --- Main Testing Function --- */
int	main(int argc, char **argv)
{
	(void)argv; /* argv is never used in any of these tests */

#ifndef EX01
	(void)argc; /* Only void argc if EX01 is NOT being compiled */
#endif

#ifdef EX01
	printf("--- EX01: ft_boolean.h ---\n");
	/* Uses the exact logic required by the subject's main */
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	printf("\n");
#endif

#ifdef EX02
	printf("--- EX02: ft_abs.h ---\n");
	printf("ABS(-42)      : %d (Expected: 42)\n", ABS(-42));
	printf("ABS(42)       : %d (Expected: 42)\n", ABS(42));
	printf("ABS(0)        : %d (Expected: 0)\n", ABS(0));
	printf("ABS(-5 - 10)  : %d (Expected: 15 - tests macro safety!)\n\n", ABS(-5 - 10));
#endif

#ifdef EX03
	printf("--- EX03: ft_point.h ---\n");
	t_point point;
	set_point(&point);
	printf("Point X: %d (Expected: 42)\n", point.x);
	printf("Point Y: %d (Expected: 21)\n\n", point.y);
#endif

#if defined(EX04) || defined(EX05)
	printf("--- EX04 & EX05: ft_strs_to_tab & ft_show_tab ---\n");
	char *strs[] = {"Hello", "42", "Piscine", "C08"};
	int ac = 4;
	
	struct s_stock_str *tab = ft_strs_to_tab(ac, strs);
	if (tab)
	{
# ifdef EX05
		ft_show_tab(tab);
# else
		printf("Tab successfully allocated! Run EX05 to print its contents.\n");
# endif
		/* Memory Leak Safeguard - Clean up after testing */
		int i = 0;
		while (tab[i].str != 0)
		{
			free(tab[i].str);
			free(tab[i].copy);
			i++;
		}
		free(tab);
	}
	else
		printf("Allocation failed!\n");
	printf("\n");
#endif

	return (0);
}
