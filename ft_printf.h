/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:48:34 by mdoll             #+#    #+#             */
/*   Updated: 2022/12/30 15:00:53 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "./libft/libft.h"

int	ft_printf(const char	*str, ...);
int	pchar(int c);
int	pstr(char *str);
int	pperc(void);
int	pdecint(int n);

#endif