/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:27:37 by mgs               #+#    #+#             */
/*   Updated: 2022/06/23 16:27:36 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

int	min_number(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	max_number(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
