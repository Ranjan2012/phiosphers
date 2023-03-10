/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmallawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:56:07 by rmallawa          #+#    #+#             */
/*   Updated: 2022/12/24 17:56:37 by rmallawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

// DEFINES

// INFORMATION FROM INPUT
typedef struct s_input
{
	long long		n_philos;
	pthread_mutex_t	*forks;
	long long		tt_die;
	long long		tt_eat;
	long long		tt_sleep;
	long long		n_must_eat[2];
	long			start_time;
	bool			death;
	pthread_mutex_t	*death_lock;
	bool			wait;
	pthread_mutex_t	*wait_lock;
	pthread_mutex_t	*print_lock;
	char			*state[7];
}			t_input;

// INFORMATION OF EACH PHILOSOPHER
typedef struct s_philo
{
	int				philo_n;
	bool			running;
	pthread_mutex_t	*running_lock;
	bool			eating;
	pthread_mutex_t	*eat_lock;
	int				fork_r;
	int				fork_l;
	pthread_t		thread_id;
	long			time_philo;
	pthread_mutex_t	*time_lock;
}			t_philo;

// ENUM FOR PRINT STATEMENTS
typedef enum e_print_statement
{
	is_eating = 0,
	grabbed_fork = 1,
	is_sleeping = 2,
	is_thinking = 3,
	is_dead = 4,
}	t_print_statement;

// UTILS_ONE
long long	ft_atol(char *str);
void		*ft_calloc(size_t nelem, size_t elsize);
long		get_time(void);
void		print_state(t_input *input, t_philo *philo, int state);

// UTILS_TWO
void		ft_sleep(long long ms);
int			print_error(void);
bool		every_philo_finished(void);
int			ft_isdigit(int c);
int			input_help(void);

// EXIT
void		free_input(void);
void		destroy_forks(void);
void		free_philos(void);
void		death_routine(t_philo *philo);

// INIT
t_philo		**init_philos(bool init);
t_philo		**get_philos(void);

// INPUT
t_input		*set_input(char **argv);
t_input		*get_input(void);

// REAPER
void		reaper(void);

// ROUTINE
void		*routine(void *arg);

// THREADS
void		thread_join(void);
int			thread_creation(t_input *input, t_philo **philos);

#endif
