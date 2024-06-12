/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:23:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/12 20:17:31 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_nb_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&(data->mut_nb_philos));
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&(data->mut_nb_philos));
	return (nb_philos);
}

int ft_get_die_time(t_data *data)
{
	int	die_time;

	pthread_mutex_lock(&(data->mut_die_time));
	die_time = data->die_time;
	pthread_mutex_unlock(&(data->mut_die_time));
	return (die_time);
}
