/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:34:42 by saazcon-          #+#    #+#             */
/*   Updated: 2022/11/15 22:36:06 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// LIBRERÍAS
# include <unistd.h>		// write
# include <stdio.h>			// printf
# include <stdlib.h>		// malloc
# include <stdarg.h>		// va_list
# include "libft/libft.h"	// ft_strlen

//FT_PRINTF
int	ft_printf(char const *valor, ...);

//FT_PUT
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(long int n);
int	ft_putnbr_base(unsigned int nbr, char *b);
int	ft_putptr_base(size_t nbr);

#endif