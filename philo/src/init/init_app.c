/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:00:57 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/08 03:32:57 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

void	init_app(t_table **table, int c, char **v)
{
	if (c == 5)
	{
		(*table)->philos_num = ft_atoi(v[1]);
		(*table)->time_to_die = ft_atoi(v[2]);
		(*table)->time_to_eat = ft_atoi(v[3]);
		(*table)->time_to_sleep = ft_atoi(v[4]);
	}
	if (c == 6)
		(*table)->eat_num = ft_atoi(v[5]);
	(*table)->head = NULL;
}

void	init_philosophers(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos_num)
		ft_add_node(&table, ft_new_node(i + 1));
}
