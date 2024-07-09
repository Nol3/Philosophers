/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:58:10 by alcarden          #+#    #+#             */
/*   Updated: 2024/07/09 14:29:40 by alcarden         ###   ########.fr       */
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
# include <signal.h>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

// STRUCTS

typedef pthread_mutex_t	t_mtx;

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	FULL,
	IDLE,
}	t_state;

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

typedef struct s_philo
{
	int					id;
	int					nb_meals_had;
	int					is_alive;
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
	pthread_mutex_t 	mut_life;
	//init
	pthread_mutex_t		mut_nb_philos;
	pthread_mutex_t		mut_keep_iter;
	pthread_mutex_t		mut_start_time;
	pthread_t			check_all_alive;
	pthread_t			check_all_full;
	pthread_t			*philo_ths;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_data;

// PROTOTYPES

//forks.c
void					ft_take_fork(t_philo philo);
void					ft_drop_fork(t_philo philo);

//set.c
void					ft_set_keep_iter(t_data *data, int value);
void 					ft_set_philo_state(t_philo *philo, t_state state);

// actions.c
void 					ft_update_last_meal_time(t_philo *philo);
void 					ft_update_nb_meals(t_philo *philo);
int						ft_philo_think(t_philo *philo);
void					ft_philo_eat(t_data *data, t_philo *philo);
int						ft_philo_sleep(t_data *data, t_philo *philo);

// gets.c  *organizar, hay más de 5*
int 					ft_get_sleep_time(t_data *data);
int						ft_get_nb_philos(t_data *data);
int						ft_get_eat_time(t_data *data);
int						ft_get_nb_meals_had(t_philo *philo);
int						ft_get_philo_state(t_philo *philo);
bool					ft_get_keep_iter(t_data *data);

// check_monitor.c
int						ft_check_full(t_data *data);
int						ft_check_alive(t_data *data);

// time.c
long					ft_start_time(void);
int						ft_usleep(long time);
long					ft_current_time(long start_time);

// gets.c
int						ft_get_nb_philos(t_data *data);
int						ft_get_eat_time(t_data *data);

// utils.c
void					ft_error_exit(const char *error);
void					ft_free_data(t_data *data);
void					ft_free_philo(t_philo *philo);
void 					ft_print_philo_state(t_philo *philo,
							t_state state, char *color);

//main.c
int						ft_create_threads(t_data *data);
void					ft_monitor_checker(t_data *data);
void					ft_dinner_check(t_data *data);
void					ft_philo(t_philo *philo);

// parse.c
int						ft_isdigit(int c);
//bool					ft_isspace(char c);
//const char			*ft_valid_args(const char *str);
//long					ft_atol(const char *str);
void					ft_parse_args(t_data *t_data, int argc, char *argv[]);

// init.c
t_philo					*init_philo(int id, t_data *data);
t_data					*init_data(int nb_philos, t_data *data);
void					update_last_meal_time(t_philo *philo);

// safe_inits.c
void					*ft_safe_malloc(size_t bytes);
void					ft_safe_mutex(t_mtx *mutex, t_opcode opcode);
void					ft_handle_thread_error(int status, t_opcode opcode);
void					ft_safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void					ft_safe_thread_handle(pthread_t *thread, void *(*foo)(void *),t_opcode opcode);

#endif