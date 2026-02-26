/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:40:27 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 02:30:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

/**
 * @fn static int ft_strlen(char *str)
 * @brief Calculates the length of a string.
 * @param str The string to measure.
 * @return The length of the string.
 */
static int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len] != '\0')
		len++;
	return (len);
}

/**
 * @fn static char *ft_strdup(char *src)
 * @brief Duplicates a string using dynamic memory allocation.
 * @details Calculates the length of the source string, allocates enough memory 
 * on the heap to store it (including the null terminator), and copies it over.
 * @param src The string to duplicate.
 * @return A pointer to the newly allocated string, or NULL if malloc fails.
 */
static char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dup = malloc (sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = src[i];
	dup[len] = '\0';
	return (dup);
}

/**
 * @fn struct s_stock_str *ft_strs_to_tab(int ac, char **av)
 * @brief Converts an array of strings into a dynamically allocated array of
 * structs.
 * @details Allocates memory for an array of t_stock_str based on the argument
 * count. Iterates through the strings to calculate sizes and dynamically
 * duplicate the string contents into the struct fields.
 * @param ac The total number of arguments.
 * @param av The argument vector array.
 * @return A pointer to the allocated struct array, or NULL on allocation error.
 */
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*arr;
	int				i;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		if (!av[i])
			return (NULL);
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = ft_strdup(av[i]);
		arr[i].copy = ft_strdup(arr[i].str);
		if (!(arr[i].str) || !(arr[i].copy))
			return (NULL);
	}
	arr[i].str = 0;
	return (arr);
}
