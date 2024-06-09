/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:58:10 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/09 23:58:11 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int				id;
	bool			full;
	long			meals_counter;
	long			last_meal_time;
	pthread_t		thread_id;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_mtx			philo_mutex;
	t_table			*table;
}				t_philo;

struct	s_table
{
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				philo_nbr;
	long				start_simulation;
	bool				end_simulation;
	bool				all_threads_ready;
	long				threads_running_nbr;
	pthread_t			monitor;
	t_fork				*forks;
	t_philo				*philos;
	t_mtx				table_mutex;
	t_mtx				write_mutex;
};


//Prototypes

void		ft_error_exit(const char *error);

#endif