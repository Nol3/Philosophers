/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:22:06 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/10 22:09:39 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	print_status(philo, philo->id, 'f');
	pthread_mutex_lock(philo->right_f);
	print_status(philo, philo->id, 'f');
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

