/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/11 14:19:06 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//./philo 5 800 200 200 [5]

int	main(int argc, char *argv[])
{
	t_data	data;

	if (5 == argc || 6 == argc)
	{
		//parse arguments
		ft_parse_args(&data, argc, argv);
	}
	else
	{
		ft_error_exit("Error: wrong input arguments\n");
	}
}

