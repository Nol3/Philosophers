/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/10 20:37:36 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//./philo 5 die 800 eat 200 sleep 200 [5] (example)

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (5 == argc || 6 == argc)
	{
		data = ft_parse_args(data, argc, argv);
		data = init_data(data->nb_philos, data);
		if(data->nb_philos == 1)
			ft_one_philo(data);
		else
		{
			ft_create_threads(data);
			ft_monitor_checker(data);
		}
		ft_free_data(data);
	}
	else
		ft_error_exit("Error: wrong input arguments\n");
	return (0);
}

void ft_one_philo(t_data *data) 
{
	data->start_time = ft_start_time();
	print_status(&data->philo[0], data->philo->id, 'f');
	ft_usleep(data->die_time);
	print_status(&data->philo[0], data->philo->id, 'd');
}

int	ft_create_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = ft_start_time();
	while (++i < data->nb_philos) 
	{
    	if (pthread_create(&data->philo_ths[i], NULL, ft_philo, &data->philo[i]) != 0) 
		{
     		ft_error_exit("Error creating philosopher thread\n");
    	}
  	}
	i = -1;
  	while (++i < data->nb_philos) 
	{
    	if (pthread_join(data->philo_ths[i], NULL) != 0) 
		{
      		ft_error_exit("Error joining philosopher thread\n");
    	}
	}
	return (0);
}

void	ft_monitor_checker(t_data *data)
{
	int	exit;

	exit = 0;
	while (1)
	{
		exit = ft_check_full(data);
		if (exit == 1)
		{
			ft_set_keep_iter(data, false);
			break ;
		}
		exit = ft_check_alive(data);
		if (exit == 1)
		{
			ft_set_keep_iter(data, false);
			break ;
		}
		ft_usleep(1000);
	}
}

void *ft_philo(void *param) 
{
	t_philo *philo;

	philo = (t_philo *)param;

	while (1)
	{
		if (!ft_get_keep_iter(philo->data)
			|| philo->nb_meals_had == philo->data->nb_meals)
			return (NULL);
		ft_philo_eat(philo);
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	return (NULL);
}
