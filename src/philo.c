/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/09/16 18:53:29 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	check_flag(t_data *data, int *flag)
{
	if (data->n_eats != -1 && *flag == 1)
	{
		pthread_mutex_lock(&data->lock);
		data->death = true;
		pthread_mutex_unlock(&data->lock);
	}
}

void	monitor(t_philo *philos, t_data *data)
{
	int			i;
	long long	time;
	int			flag;

	while (!get_death(data))
	{
		i = -1;
		flag = 1;
		while (++i < data->n_philo)
		{
			if (get_t_death(data) < (get_time() - get_l_meal(&philos[i])))
			{
				pthread_mutex_lock(&data->lock);
				data->death = true;
				time = get_time() - get_t_start(data);
				printf(MSG_DIE, time, philos[i].id);
				pthread_mutex_unlock(&data->lock);
				break ;
			}
			if (data->n_eats != -1 && get_n_meals(&philos[i]) < data->n_eats)
				flag = 0;
		}
		check_flag(data, &flag);
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	pthread_mutex_lock(&philo->m_mutex);
	philo->lmeal = get_time();
	pthread_mutex_unlock(&philo->m_mutex);
	if (philo->data->n_philo == 1)
		return (one_philo(philo));
	while (!get_death(philo->data))
	{
		if (!get_death(philo->data))
		{
			if (p_eat(philo) != -1)
			{
				pthread_mutex_lock(&philo->m_mutex);
				philo->nmeals++;
				pthread_mutex_unlock(&philo->m_mutex);
			}
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
	pthread_mutex_lock(&philos->data->lock);
	while (i < philos->data->n_philo)
	{
		if (pthread_create(&philos[i].pthread, NULL, &routine, &philos[i]) != 0)
			return (pthread_mutex_unlock(&philos->data->lock), NULL);
		i++;
	}
	philos->data->t_start = get_time();
	pthread_mutex_unlock(&philos->data->lock);
	monitor(philos, philos->data);
	i = 0;
	while (i < philos->data->n_philo)
	{
		pthread_join(philos[i].pthread, NULL);
		i++;
	}
	return (philos);
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
