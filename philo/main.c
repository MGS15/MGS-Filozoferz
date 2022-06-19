/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:24:18 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/19 21:24:28 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/headers/philosophers.h"

void	print_philo(t_table *table)
{
	t_philosofer	*tmp;
	int				i;

	i = -1;
	tmp = table->head;
	printf("***********************************\n");
	printf("philos_num: %d\n", table->philos_num);
	printf("eat_num: %d\n", table->eat_num);
	printf("time_to_die: %d\n", table->time_to_die);
	printf("time_to_eat: %d\n", table->time_to_eat);
	printf("time_to_sleep: %d\n", table->time_to_sleep);
	while (++i < table->philos_num)
	{
		printf("Philosopher ID: %d\n", tmp->philo_id);
		tmp = tmp->next_philo;
	}
}

int	main(int c, char **v)
{
	t_table			*table;
	t_philosofer	*ph;

	if (!manage_inputs(c, v))
		return (2);
	table = malloc(sizeof(t_table));
	if (!table)
		return (2);
	if (!init_app(&table, c, v))
		return (2);
	if (!init_philosophers(table))
		return (2);
	if (!init_mutexes(&table))
		return (2);
	if (!create_threads(table))
		return (2);
	ph = table->head;
	while (1)
	{
		if (ph->table->time_to_die < time_now(ph->table) - ph->last_meal || \
			table->how_many_eats == table->philos_num)
		{
			behaviour(time_now(table), ph->philo_id, "died", table);
			free_all(&table);
			return (0);
		}
		ph = ph->next_philo;
	}
	join_threads(table);
	destroy_mutexes(&table);
	
	return (0);
}
