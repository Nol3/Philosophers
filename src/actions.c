/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:12 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/17 20:55:59 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//PLACEHOLDER FUNCTIONS

void ft_update_last_meal_time(t_philo *philo)
{
    ft_safe_mutex_handle(&philo->mut_last_eat_time, LOCK);
    philo->last_eat_time = ft_start_time();
    ft_safe_mutex_handle(&philo->mut_last_eat_time, UNLOCK);
}

void ft_update_nb_meals(t_philo *philo)
{
    ft_safe_mutex_handle(&philo->mut_nb_meals_had,LOCK);
    philo->nb_meals_had++;
    ft_safe_mutex_handle(&philo->mut_nb_meals_had,UNLOCK);
}

//MAGENTA FOR EATING
// void ft_philo_eat(t_philo *philo)
// {
	//TODO
// }

//CYAN FOR SLEEPING
int ft_philo_sleep(t_data *data, t_philo *philo)
{
	ft_set_philo_state(philo, SLEEPING);
    if (ft_get_philo_state(philo) == DEAD)
        return (1);
    ft_print_philo_state(philo, SLEEPING, CYAN);
    ft_usleep(ft_get_sleep_time(data));
    return (0);
}
//GREEN FOR THINKING
int ft_philo_think(t_data *data, t_philo *philo)
{
    ft_set_philo_state(philo, THINKING);
    if (ft_get_philo_state(philo) == DEAD)
        return (1);
    ft_print_philo_state(philo, THINKING, GREEN);
    return (0);
}