/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:22:06 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/27 15:23:50 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_f);
	ft_print_philo_state(philo, EATING, GREEN);
	pthread_mutex_lock(philo->right_f);
	ft_print_philo_state(philo, EATING, GREEN);
}

void	ft_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

