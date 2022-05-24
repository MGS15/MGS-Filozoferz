/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:45:27 by sel-kham          #+#    #+#             */
/*   Updated: 2022/05/23 19:47:39 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_philosophers
{
	int	philos_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_num;
}	t_philosophers;