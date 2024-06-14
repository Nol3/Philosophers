/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:58:10 by alcarden          #+#    #+#             */
/*   Updated: 2024/06/14 20:59:42 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <inttypes.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

typedef struct s_philo
{
	int					id;
	int					nb_meals_had;
	struct s_data		*data;
	t_state				state;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	pthread_mutex_t		mut_state;
	pthread_mutex_t		mut_nb_meals_had;
	pthread_mutex_t		mut_last_eat_time;
	u_int64_t			last_eat_time;
}						t_philo;

typedef struct s_data
{
	int					nb_philos;
	bool				keep_iterating;
	u_int64_t			die_time;
	u_int64_t			eat_time;
	u_int64_t			sleep_time;
	int					nb_meals;
	int					nb_full_p;
	u_int64_t			start_time;
	pthread_mutex_t		mut_eat_t;
	pthread_mutex_t		mut_die_t;
	pthread_mutex_t		mut_sleep_t;
	pthread_mutex_t		mut_print;
	pthread_mutex_t		mut_nb_philos;
	pthread_mutex_t		mut_keep_iter;
	pthread_mutex_t		mut_start_time;
	pthread_t			check_all_alive;
	pthread_t			check_all_full;
	pthread_t			*philo_ths;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_data;

// Prototypes

// gets.c
int						ft_get_nb_philos(t_data *data);
int						ft_get_die_time(t_data *data);

// check_monitor.c
int						ft_check_full(t_data *data);
int						ft_check_alive(t_data *data);

// time.c
long					ft_start_time(void);
void					ft_usleep(long time);
long					ft_current_time(long start_time);

// gets.c
int						ft_get_nb_philos(t_data *data);
int						ft_get_eat_time(t_data *data);

// utils.c
void					ft_error_exit(const char *error);

//main.c
void 					ft_dinner_check(t_data *data);

// parse.c
int						ft_isdigit(int c);
static bool				ft_isspace(char c);
static const char		*ft_valid_args(const char *str);
static long				ft_atol(const char *str);
void					ft_parse_args(t_data *t_data, int argc, char *argv[]);

// init.c
t_philo					*init_philo(int id, t_data *data);
t_data					*init_data(int nb_philos);
void					update_last_meal_time(t_philo *philo);

// safe_inits.c
void					ft_safe_malloc(size_t bytes);
void					ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
static void				ft_handle_thread_error(int status, t_opcode opcode);
void					ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void					ft_safe_thread_handle(pthread_t *thread, 
					void *(*foo)(void *), void *data, t_opcode opcode)

#endif