/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:23:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/29 15:02:27 by alcarden         ###   ########.fr       */
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

int ft_get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&(data->mut_sleep_t));
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&(data->mut_sleep_t));
	return (sleep_time);
}

int 	ft_get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&(data->mut_eat_t));
	eat_time = data->eat_time;
	pthread_mutex_unlock(&(data->mut_eat_t));
	return (eat_time);
}

int ft_get_nb_meals_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&(philo->mut_nb_meals_had));
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&(philo->mut_nb_meals_had));
	return (nb_meals_had);
}

int ft_get_philo_state(t_philo *philo)
{
	int	state;

	pthread_mutex_lock(&(philo->mut_state));
	state = philo->state;
	pthread_mutex_unlock(&(philo->mut_state));
	return (state);
}

bool ft_get_keep_iter(t_data *data)
{
	bool	keep_iter;

	pthread_mutex_lock(&(data->mut_keep_iter));
	keep_iter = data->keep_iterating;
	pthread_mutex_unlock(&(data->mut_keep_iter));
	return (keep_iter);
}
