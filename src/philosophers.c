/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/09 23:58:38 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//./philo 5 800 200 200 [5]

int	main (int argc, char *argv[])
{
	t_table	table;

	if (5 == argc || 6 == argc)
	{
		//parse arguments
	}
	else
	{
		ft_error_exit("Error: wrong input arguments\n");
	}
}