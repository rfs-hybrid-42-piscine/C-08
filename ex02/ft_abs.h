/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:37:49 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/26 02:44:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

/**
 * @def ABS(Value)
 * @brief Macro to dynamically evaluate the absolute value of a number.
 * @details Uses mathematical boolean evaluation to bypass the 42 Norm's 
 * restriction on ternary operators. Every instance of the parameter is 
 * strictly wrapped in parentheses to prevent order-of-operation bugs 
 * during preprocessor expansion.
 */
# define ABS(Value) ((Value) * (((Value) > 0) - ((Value) < 0)))

#endif
