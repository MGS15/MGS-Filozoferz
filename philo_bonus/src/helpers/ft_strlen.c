/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:11:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/23 16:27:03 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		;
	return (i);
}
