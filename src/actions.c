/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:12 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/10 19:48:53 by alcarden         ###   ########.fr       */
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
void ft_philo_eat(t_philo *philo)
{
    ft_set_philo_state(philo, EATING);
    if (ft_get_philo_state(philo) == DEAD)
        return ;
    ft_take_fork(philo);
    print_status(philo, philo->id, 'e');
    ft_update_last_meal_time(philo);
    ft_usleep(philo->data->eat_time);
    ft_drop_fork(philo);
    ft_update_nb_meals(philo);
}

//CYAN FOR SLEEPING
void ft_philo_sleep(t_philo *philo)
{
	ft_set_philo_state(philo, SLEEPING);
    if (ft_get_philo_state(philo) == DEAD)
        return ;
    print_status(philo, philo->id, 's');
    ft_usleep(philo->data->sleep_time);
}
//GREEN FOR THINKING
void ft_philo_think(t_philo *philo)
{
    int time_think;

    if (philo->data->nb_philos % 2 == 0)
        time_think = philo->data->eat_time - philo->data->sleep_time;
    else
        time_think = philo->data->eat_time * 2 - philo->data->sleep_time;
    if (time_think <= 0)
        return ;
    ft_set_philo_state(philo, THINKING);
    if (ft_get_philo_state(philo) == DEAD)
        return ;
    print_status(philo, philo->id, 't');
}
