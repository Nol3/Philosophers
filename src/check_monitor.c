/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:42:21 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/20 18:35:19 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_full(t_data *data)
{
	int	i;
	int	number_of_philos;

	i = 0;
	number_of_philos = ft_get_nb_philos(data);
	while (i < number_of_philos)
	{
		if (data->philos[i].nb_meals_had < data->nb_meals)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_alive(t_data *data)
{
	int	i;
	int	number_of_philos;

	i = -1;
	number_of_philos = ft_get_nb_philos(data);
	while (++i < number_of_philos)
	{
		if (ft_start_time() - data->philos[i].last_eat_time > data->die_time)
		{
			ft_set_philo_state(&data->philos[i], DEAD);
			return (1);
		}
	}
	return (0);
}
