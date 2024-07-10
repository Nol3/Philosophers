/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:42:21 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/10 20:40:31 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_full(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (data->philo[i].nb_meals_had < data->nb_meals)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_alive(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
	{
		if (ft_start_time() - data->philo[i].last_eat_time > data->die_time)
		{
			ft_set_philo_state(&data->philo[i], DEAD);
			ft_set_keep_iter(data, false);
			return (1);
		}
	}
	return (0);
}
