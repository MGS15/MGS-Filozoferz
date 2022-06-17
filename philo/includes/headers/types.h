/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgs <mgs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:45:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/06/17 18:40:35 by mgs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H

# define TYPES_H

# include "philosophers.h"

typedef struct s_table	t_table;
typedef struct s_philosopher
{
	int						philo_id;
	pthread_t				philosopher;
	pthread_mutex_t			fork;
	struct s_philosopher	*next_philo;
	struct s_philosopher	*prev_philo;
	bool					is_dead;
	long					last_meal;
	int						num_times_eat;
	t_table					*table;
}	t_philosofer;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	long			t0;
	int				someonedied;
	t_philosofer	*head;
}	t_table;

#endif