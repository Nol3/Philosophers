/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:47:44 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/11 14:26:30 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static bool	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || 32 == c)
		return (true);
	return (false);
}

static const char	*ft_valid_args(const char *str)
{
	int			len;
	conts char	*num;

	len = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		ft_error_exit("Error: wrong input, only positives numbers\n");
	if (!ft_isdigit(*str))
		ft_error_exit("Error: wrong input, only numbers\n");
	num = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		ft_error_exit("Error: wrong input, number too big\n");
	return (num);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = ft_valid_args(str);
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		++str;
	}
	if (num > INT_MAX)
		ft_error_exit("Error: wrong input, number too big\n");
}

void	ft_parse_args(t_data *t_data, int argc, char *argv[])
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t)ft_atoi(argv[2]);
	data->eat_time = (u_int64_t)ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	if (argc == 6)
		t_data->nb_meals = ft_atol(argv[5]);
	else
		t_data->nb_meals = -1;
	if (t_data->nb_philos < 2 || t_data->nb_philos > 200)
		ft_error_exit("Error: wrong input, number of philos\n");
	if (t_data->eat_time < 60 || t_data->sleep_time < 60
		|| t_data->think_time < 60)
		ft_error_exit("Error: wrong input, time too short\n");
	if (t_data->nb_meals < 1)
		ft_error_exit("Error: wrong input, number of meals\n");
}

