/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:59:53 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 02:27:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

/**
 * @struct s_point
 * @brief Custom data structure defining a 2D coordinate point.
 * @param x The horizontal coordinate.
 * @param y The vertical coordinate.
 */
typedef struct point
{
	int	x;
	int	y;
}	t_point;

void	set_point(t_point *point);

#endif
