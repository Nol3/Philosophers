/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:54:59 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/12 14:46:33 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)ft_safe_malloc(sizeof(t_philo));
	philo->id = id;
	philo->nb_meals_had = 0;
	philo->data = data;
	philo->state = THINKING;
	philo->left_f = ft_safe_malloc(sizeof(pthread_mutex_t));
	philo->right_f = ft_safe_malloc(sizeof(pthread_mutex_t));
	ft_safe_mutex_handle(&(philo->mut_state), INIT);
	ft_safe_mutex_handle(&(philo->mut_nb_meals_had), INIT);
	ft_safe_mutex_handle(&(philo->mut_last_eat_time), INIT);
	philo->last_eat_time = 0;
	return (philo);
}

t_data	*init_data(int nb_philos)
{
	int     i;
    t_data  *data;

	i = -1;
	t_data *data = (t_data *)ft_safe_malloc(sizeof(t_data));
	data->nb_full_p = 0;
	data->start_time = 0;
	ft_safe_mutex_handle(&(data->mut_eat_t), INIT);
	ft_safe_mutex_handle(&(data->mut_die_t), INIT);
	ft_safe_mutex_handle(&(data->mut_sleep_t), INIT);
	ft_safe_mutex_handle(&(data->mut_print), INIT);
	ft_safe_mutex_handle(&(data->mut_nb_philos), INIT);
	ft_safe_mutex_handle(&(data->mut_keep_iter), INIT);
	ft_safe_mutex_handle(&(data->mut_start_time), INIT);
	data->philo_ths = ft_safe_malloc(nb_philos * sizeof(pthread_t));
	data->forks = ft_safe_malloc(nb_philos * sizeof(pthread_mutex_t));
	data->philos = ft_safe_malloc(nb_philos * sizeof(t_philo));
	while (++i < data->nb_philos)
	{
		data->philos[i] = *init_philo(i, data);
		ft_safe_mutex_handle(&(data->forks[i]), INIT);
	}
	return (data);
}
