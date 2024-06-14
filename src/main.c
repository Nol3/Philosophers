/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/12 20:00:08 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//./philo 5 800 200 200 [5]

int	main(int argc, char *argv[])
{
	t_data	data;

	if (5 == argc || 6 == argc)
	{
		ft_parse_args(&data, argc, argv);
		data = *init_data(data->nb_philos);
		ft_monitor_checker(&data);
		ft_dinner_check(&data);
		ft_create_threads(&data);
	}
	else
		ft_error_exit("Error: wrong input arguments\n");
}

int	ft_create_threads(t_data *data)
{
	int	i;
	int	number_of_philos;

	i = -1;
	number_of_philos = ft_get_nb_philos(data);
	data->start_time = ft_start_time();
	while (++i < number_of_philos)
	{
		ft_safe_thread_handle();
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
			break ;
		exit = ft_check_alive(data);
		if (exit == 1)
			break ;
	}
}

void ft_dinner_check(t_data *data)
{
	if (data->nb_meals == 0)
		ft_error_exit("Error: Number of meals incorrect.\n")
	else if (data->nb_philos == 1)
	{
		//Condición específica
	}
}