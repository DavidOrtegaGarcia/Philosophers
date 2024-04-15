/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:56 by daortega          #+#    #+#             */
/*   Updated: 2024/04/15 18:01:12 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

/*--------------STRUCTS--------------*/
typedef struct s_data
{
	int				n_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				n_eats;
	struct s_philo	*philo;
	// forks
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		pthread;
	int				lfork;
	int				rfork;
	t_data			*data;
}					t_philo;

/*--------------HEADERS--------------*/
t_data				fill_data(int argc, char *argv[]);
int					atoi(char *str);
void				print_data(t_data data);
void	free_philos(t_philo *philos);
void	free_forks(pthread_mutex_t *forks, t_data data);
#endif