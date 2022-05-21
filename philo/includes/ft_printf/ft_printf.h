/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:32:17 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/21 15:08:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c, int *i);
void	ft_putstr(char *s, int *count);
void	ft_putnbr_base(char *base, long num, int *count);
void	ft_putnbr_base_p(char *base, unsigned long num, int *count);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);

#endif