/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:42:21 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/14 18:27:44 by alcarden         ###   ########.fr       */
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
	int	time;

	i = -1;
	number_of_philos = ft_get_nb_philos(data);
	time = ft_get_die_time(data);
	while (++i < number_of_philos)
	{
		//mutex
		if (ft_get_time() - data->philos[i].last_eat_time > time)
		{
			//mutex
			return (0);
		}
		//Mutex
	}
	return (1);
}
