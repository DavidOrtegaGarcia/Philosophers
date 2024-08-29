/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:56 by daortega          #+#    #+#             */
/*   Updated: 2024/08/29 17:01:05 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

/*============== MACROS ==============*/
# define MSG_FRK "%lld %d has taken a fork\n"
# define MSG_EAT "%lld %d is eating\n"
# define MSG_ZZZ "%lld %d is sleeping\n"
# define MSG_THK "%lld %d is thinking\n"
# define MSG_DIE "%lld %d died\n"

/*--------------STRUCTS--------------*/
typedef struct s_data
{
	int				n_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				n_eats;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	bool			death;
	long long		t_start;
	pthread_mutex_t	getter;
	pthread_mutex_t	lock;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	long long		lmeal;
	int				nmeals;
	t_data			*data;
}					t_philo;

/*--------------HEADERS--------------*/
int			fill_data(int argc, char *argv[], t_data *data);
bool		ft_test_atoi(char *str);
int			ft_atoi(char *str);
int			check_val_arg(t_data data);
void		print_data(t_data data);
void		free_philos(t_philo *philos);
void		free_forks(pthread_mutex_t *forks, t_data data);
t_philo		*fill_philos(t_philo *philos, t_data *data);
t_philo		*create_philos(t_philo *philos);
void		print_forks(t_philo *philos);
long long	get_time(void);
int			get_t_death(t_data *data);
int			get_t_eat(t_data *data);
int			get_t_sleep(t_data *data);
int			get_n_eats(t_data *data);
bool		get_death(t_data *data);
long long	get_t_start(t_data *data);

#endif