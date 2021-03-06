/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:36:59 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/22 15:33:08 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers.h"

bool	create_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		tmp->last_meal = time_now(table);
		if (pthread_create(&(tmp->philosopher), NULL,
				philosophers_handler, (void *) tmp))
			return (false);
		tmp = tmp->next_philo;
	}
	return (true);
}

bool	join_threads(t_table *table)
{
	int				i;
	t_philosofer	*tmp;

	i = -1;
	tmp = table->head;
	while (++i < table->philos_num)
	{
		if (pthread_detach(tmp->philosopher))
			return (false);
		tmp = tmp->next_philo;
	}
	return (true);
}

bool	init_mutexes(t_table **table)
{
	int				i;

	i = -1;
	(*table)->forks = malloc(sizeof(pthread_mutex_t) * (*table)->philos_num);
	if (!(*table)->forks)
		return (NULL);
	pthread_mutex_init(&((*table)->print_locker), NULL);
	while (++i < (*table)->philos_num)
		if (pthread_mutex_init(&((*table)->forks[i]), NULL))
			return (false);
	return (table);
}

bool	destroy_mutexes(t_table **table)
{
	int				i;

	i = -1;
	pthread_mutex_destroy(&((*table)->print_locker));
	while (++i < (*table)->philos_num)
		if (!pthread_mutex_destroy(&(*table)->forks[i]))
			return (false);
	return (true);
}
