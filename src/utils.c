/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:29:24 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/17 16:54:59 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void ft_free_data(t_data *data)
{
	int i;
	int nb_philos;

	i = -1;
	nb_philos = ft_get_nb_philos(data);
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&(data->philos[i].mut_state));
		pthread_mutex_destroy(&(data->philos[i].mut_nb_meals_had));
		pthread_mutex_destroy(&(data->philos[i].mut_last_eat_time));
		pthread_mutex_destroy(data->philos[i].left_f);
		pthread_mutex_destroy(data->philos[i].right_f);
	}
	pthread_mutex_destroy(&(data->mut_eat_t));
	pthread_mutex_destroy(&(data->mut_die_t));
	pthread_mutex_destroy(&(data->mut_sleep_t));
	pthread_mutex_destroy(&(data->mut_print));
	pthread_mutex_destroy(&(data->mut_nb_philos));
	pthread_mutex_destroy(&(data->mut_keep_iter));
	pthread_mutex_destroy(&(data->mut_start_time));
	free(data->philo_ths);
	free(data->forks);
	free(data->philos);	
	ft_free_philo(data->philos);
	free(data);	
}

void ft_free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->mut_state));
	pthread_mutex_destroy(&(philo->mut_nb_meals_had));
	pthread_mutex_destroy(&(philo->mut_last_eat_time));
	pthread_mutex_destroy(philo->left_f);
	pthread_mutex_destroy(philo->right_f);
	free(philo);
}
