/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:34:11 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/24 04:19:01 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/philosophers_bonus.h"

void	init_sem(t_table **table)
{
	int	i;

	i = -1;
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_death");
	sem_unlink("sem_full");
	(*table)->sem_fork = sem_open("sem_fork", O_CREAT, 0777, \
								(*table)->philos_num);
	(*table)->sem_print = sem_open("sem_print", O_CREAT, 0777, 1);
	(*table)->sem_death = sem_open("sem_death", O_CREAT, 0777, 1);
	(*table)->sem_full = sem_open("sem_full", O_CREAT, 0777, 1);
	if ((*table)->sem_fork == SEM_FAILED || (*table)->sem_print == SEM_FAILED \
		|| (*table)->sem_death == SEM_FAILED \
		|| (*table)->sem_full == SEM_FAILED)
	{
		exit(EXIT_FAILURE);
	}
}

void	*check_death(void *ptr)
{
	t_table	*table;

	table = (t_table *) ptr;
	while (1)
	{
		if (table->time_to_die < time_now(table) - table->last_meal \
			&& table->eat_num == -1)
		{
			sem_wait(table->sem_print);
			printf("%ld %d %s\n", time_now(table), table->philo_id, "died");
			sem_post(table->sem_death);
			return (NULL);
		}
		if (table->num_times_eat == table->eat_num)
			sem_post(table->sem_full);
	}
	return (table);
}

void	routing(t_table *table, int i)
{
	pthread_t	th;

	table->philo_id = i + 1;
	pthread_create(&th, NULL, check_death, (void *) table);
	while (true)
	{
		eating(table);
		sleeping(table);
		thinking(table);
	}
}
