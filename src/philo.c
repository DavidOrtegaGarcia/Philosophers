/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/08/26 18:22:32 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	free_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->n_philo)
	{
		free(&philos[i]);
		i++;
	}
}

void p_think(t_philo *philo)
{
	printf(MSG_THK, get_time() - get_t_start(philo->data), philo->id);
}

void p_sleep(t_philo *philo)
{
	printf(MSG_ZZZ, get_time() - get_t_start(philo->data), philo->id);
	usleep(get_t_sleep(philo->data) * 1000);
}

void p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	printf(MSG_FRK, get_time() - get_t_start(philo->data), philo->id);
	pthread_mutex_lock(philo->rfork);
	printf(MSG_FRK, get_time() - get_t_start(philo->data), philo->id);
	printf(MSG_EAT, get_time() - get_t_start(philo->data), philo->id);
	usleep(get_t_eat(philo->data) * 1000);
	philo->lmeal = get_time();
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

void monitor(t_philo *philo, int n_philo)
{
	int i;

	while(!get_death(philo->data))
	{
		i = 0;
		while(i < n_philo)
		{
			//printf("%d --- %lld\n", get_t_death(philo->data), (get_time() - philo[i].lmeal));
			if (get_t_death(philo->data) < (get_time() - philo[i].lmeal))
			{
				pthread_mutex_lock(&philo->data->lock);
				philo->data->death = true;
				pthread_mutex_unlock(&philo->data->lock);
				printf(MSG_DIE, get_time() - get_t_start(philo->data), philo->id);
				exit(122345676);
				break;
			}
			i++;
		}
	}
}

void	*routine(void *data)
{
	t_philo *philo;

	philo = data;
	while(!get_death(philo->data))
	{
		if (!get_death(philo->data))
			p_eat(philo);
		if (!get_death(philo->data))
			p_sleep(philo);
		if (!get_death(philo->data))
			p_think(philo);
	}
	return(philo);
}

t_philo	*create_philos(t_philo *philos)
{
	int	i;

	i = 0;
	philos->data->t_start = get_time();
	while (i < philos->data->n_philo)
	{
		if (pthread_create(&philos[i].pthread, NULL, &routine, &philos[i]) != 0)
			return (NULL);
		i++;
		if(i % 2 == 0)
			usleep(10);
	}
	/////monitor
	monitor(philos, philos->data->n_philo);
	i = 0;
	while (i < philos->data->n_philo)
	{
		pthread_join(philos[i].pthread, NULL);
		i++;
	}
	return (philos);
}

void get_forks(t_philo *phil, int i)
{
	if (i == 0)
	{
		phil->lfork = &phil->data->forks[phil->data->n_philo - 1];
		phil->rfork = &phil->data->forks[0];
	}
	else
	{
		phil->lfork = &phil->data->forks[i - 1];
		phil->rfork = &phil->data->forks[i];
	}

}

t_philo	*fill_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].lmeal = get_time();
		get_forks(&philos[i], i);
		i++;
	}
	return (philos);
}
