/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/12 14:05:35 by alcarden         ###   ########.fr       */
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
		//mirar como hacer el bucle de los filosofos
	}
	else
		ft_error_exit("Error: wrong input arguments\n");
}
