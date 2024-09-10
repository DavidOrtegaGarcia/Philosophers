/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/09/10 16:28:32 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	monitor(t_philo *philos, t_data *data)
{
	int	i;

	while (!get_death(data))
	{
		i = 0;
		while (++i < data->n_philo)
		{
			if (get_t_death(data) < (get_time() - get_l_meal(&philos[i])))
			{
				pthread_mutex_lock(&data->lock);
				data->death = true;
				pthread_mutex_unlock(&data->lock);
				printf(MSG_DIE, get_time() - get_t_start(data), philos->id);
				break ;
			}
			if (data->n_eats != -1 && get_n_meals(&philos[i]) >= data->n_eats)
			{
				pthread_mutex_lock(&data->lock);
				data->death = true;
				pthread_mutex_unlock(&data->lock);
				break ;
			}
		}
	}
}

void	ft_sleep(t_data *data)
{
	while (!get_death(data) && get_t_eat(data) > get_time() - get_t_start(data))
		usleep(1000);
}

void	p_think(t_philo *philo)
{
	printf(MSG_THK, get_time() - get_t_start(philo->data), philo->id);
}

void	p_sleep(t_philo *philo)
{
	printf(MSG_ZZZ, get_time() - get_t_start(philo->data), philo->id);
	usleep(get_t_sleep(philo->data) * 1000);
}

int	p_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->lfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->lfork), -1);
		printf(MSG_FRK, get_time() - get_t_start(philo->data), philo->id);
		pthread_mutex_lock(philo->rfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->rfork),
				pthread_mutex_unlock(philo->lfork), -1);
	}
	else
	{
		pthread_mutex_lock(philo->rfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->rfork), -1);
		printf(MSG_FRK, get_time() - get_t_start(philo->data), philo->id);
		pthread_mutex_lock(philo->lfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->lfork),
				pthread_mutex_unlock(philo->rfork), -1);
	}
	printf(MSG_FRK, get_time() - get_t_start(philo->data), philo->id);
	if (get_death(philo->data))
		return (pthread_mutex_unlock(philo->rfork),
			pthread_mutex_unlock(philo->lfork), -1);
	printf(MSG_EAT, get_time() - get_t_start(philo->data), philo->id);
	ft_sleep(philo->data);
	pthread_mutex_lock(&philo->m_mutex);
	philo->lmeal = get_time();
	pthread_mutex_unlock(&philo->m_mutex);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	return (1);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	while (!get_death(philo->data))
	{
		if (!get_death(philo->data))
		{
			p_eat(philo);
			pthread_mutex_lock(&philo->m_mutex);
			philo->nmeals++;
			pthread_mutex_unlock(&philo->m_mutex);
		}
		if (!get_death(philo->data))
			p_sleep(philo);
		if (!get_death(philo->data))
			p_think(philo);
	}
	return (philo);
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
	}
	monitor(philos, philos->data);
	i = 0;
	if (philos->data->n_philo == 1)
		pthread_detach(philos[0].pthread);
	else
	{
		while (i < philos->data->n_philo)
		{
			pthread_join(philos[i].pthread, NULL);
			i++;
		}
	}
	return (philos);
}

void	get_forks(t_philo *phil, int i)
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
		philos[i].nmeals = 0;
		get_forks(&philos[i], i);
		if (pthread_mutex_init(&philos[i].m_mutex, NULL) != 0)
			return (NULL);
		i++;
	}
	return (philos);
}
