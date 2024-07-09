/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:33:26 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/09 14:32:12 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesa.h"

//./mesa 5 800 200 200 [5] (example)

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (5 == argc || 6 == argc)
	{
		ft_parse_args(data, argc, argv);
		data = init_data(data->nb_philos, data);
		ft_create_therads(data);
		ft_monitor_checker(data);
		//ft_dinner_check(data);
		ft_free_data(data);
	}
	else
		ft_error_exit("Error: wrong input arguments\n");
	return (0);
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
    	if (pthread_create(data->philo_ths[i], NULL, ft_philo, &data->philos[i]) != 0) 
		{
     		ft_error_exit("Error creating philosopher thread\n");
    	}
		printf("Philosopher %d thread created\n", i + 1);
  	}
	i = -1;
  	while (++i < number_of_philos) 
	{
    	if (pthread_join(data->philo_ths[i], NULL) != 0) 
		{
      		ft_error_exit("Error joining philosopher thread\n");
    	}
	}
	return (0); // Success
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
		ft_usleep(1000);
	}
}

// void	ft_dinner_check(t_data *data)
// {
// 	if (data->nb_meals == 0)
// 		ft_error_exit("Error: Number of meals incorrect.\n");
// 	else if (data->nb_philos == 1)
// 	{
// 		//Condición específica cuando solo hay un filósofo
// 	}
// }

void *ft_philo(void *param) {
  t_philo *mesa;

  mesa = (t_philo *)param;

  // Initial meal time (assuming get_time() returns milliseconds)
  mesa->last_eat_time = get_time() - mesa->data->start_time;

  if (mesa->data->nb_philos == 1 || mesa->data->nb_meals == 0) {
    // Handle single philosopher or no limit on meals
    one_philo(mesa);
  } else {
    // Loop for philosopher actions (thinking, eating, sleeping)
    while (1) {
      // Check if simulation is over
      pthread_mutex_lock(&mesa->data->mut_keep_iter);
      if (!mesa->data->keep_iterating) {
        pthread_mutex_unlock(&mesa->data->mut_keep_iter);
        break;
      }
      pthread_mutex_unlock(&mesa->data->mut_keep_iter);

      // Philosopher might think for a while
      ft_usleep(rand() % (mesa->data->think_time));

      // Try to pick up forks (replace with your pick_f implementation)
      pick_f(mesa);

      // Check if philosopher starved while waiting for forks
      if (has_starved(mesa)) {
        print_status(mesa->data, mesa->id, 'd');
        pthread_mutex_lock(&mesa->data->mut_keep_iter);
        mesa->data->keep_iterating = false; // Stop simulation
        pthread_mutex_unlock(&mesa->data->mut_keep_iter);
        break;
      }

      // Eat if forks are acquired
      mufasa(mesa);

      // Check if philosopher has eaten the required number of meals
      pthread_mutex_lock(&mesa->mut_nb_meals_had);
      if (mesa->data->nb_meals > 0 && mesa->nb_meals_had >= mesa->data->nb_meals) {
        mesa->data->nb_full_p++; // Increment number of full philosophers
        pthread_mutex_unlock(&mesa->mut_nb_meals_had);
        break;
      }
      pthread_mutex_unlock(&mesa->mut_nb_meals_had);
    }
  }

  // Philosopher is done, release resources (replace with your drop_f implementation)
  drop_f(mesa);
  return (NULL);
}

void one_philo(t_philo *mesa) 
{
  if (mesa->data->nb_meals == 0)
	return;
  else 
  {
	pthread_mutex_lock(mesa->left_f);
	print_status(mesa->data, mesa->id, 'f');
	pthread_mutex_unlock(mesa->left_f);
  }
}

void	print_status(t_philo *mesa, int index, char s)
{
	pthread_mutex_lock(mesa->data->mut_print);
	pthread_mutex_lock(mesa->data->mut_life);
	if (mesa->vivos)
	{
		printf("%ld %i %s\n", get_time() - mesa->t_start, index, select_s(s));
		if (s == 'd')
			mesa->data->keep_iterating = false;
	}
	pthread_mutex_unlock(mesa->date->mut_life);
	pthread_mutex_unlock(mesa->date->mut_print);
}

char	*select_s(char s)
{
	if (s == 'f')
		return ("has taken a fork");
	else if (s == 'e')
		return ("is eating");
	else if (s == 's')
		return ("is sleeping");
	else if (s == 't')
		return ("is thinking");
	else if (s == 'd')
		return ("died");
	return (NULL);
}

