/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/20 20:37:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//./philo 5 800 200 200 [5] (example)

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (5 == argc || 6 == argc)
	{
		ft_parse_args(data, argc, argv);
		data = init_data(data->nb_philos, data);
		ft_monitor_checker(data);
		ft_dinner_check(data);
		ft_create_threads(data);
	}
	else
		ft_error_exit("Error: wrong input arguments\n");
}
//PLACEHOLDER
int	ft_create_threads(t_data *data)
{
	int	i;
	int	number_of_philos;

	i = -1;
	number_of_philos = ft_get_nb_philos(data);
	data->start_time = ft_start_time();
	while (++i < number_of_philos)
	{
		//Crear los hilos e imprimir lo básico
		//ft_safe_thread_handle(data->philo_ths[i], (void*)&ft_philo, (void*)&data->philos[i], CREATE);
		// Verificación adicional después de crear los hilos
		printf("Thread %d created for Philo %d\n", i, data->philos[i].id);
		printf("Philo %d: left_f = %p, right_f = %p\n", data->philos[i].id, (void*)data->philos[i].left_f, (void*)data->philos[i].right_f);
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

void	ft_dinner_check(t_data *data)
{
	if (data->nb_meals == 0)
		ft_error_exit("Error: Number of meals incorrect.\n");
	else if (data->nb_philos == 1)
	{
		//Condición específica cuando solo hay un filósofo
	}
}

//PLACEHOLDER
// void	ft_philo(t_philo *philo)
// {
// 	while (1)
// 	{
// 		ft_philo_think(philo);
// 		ft_philo_eat(philo);
// 		ft_philo_sleep(philo);
// 	}
// }

