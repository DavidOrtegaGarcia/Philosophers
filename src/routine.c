/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:43:31 by daortega          #+#    #+#             */
/*   Updated: 2024/09/12 16:04:03 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	ft_sleep(t_data *data, int time)
{

	long long time_sleep;

	time_sleep = get_time() + time;
	while (!get_death(data) && get_time() < time_sleep)
		usleep(1000);
}

void	p_think(t_philo *philo)
{
	writer(MSG_THK, philo);
}

void	p_sleep(t_philo *philo)
{
	writer(MSG_ZZZ, philo);
	ft_sleep(philo->data, get_t_sleep(philo->data));
}

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->lfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->lfork), -1);
		writer(MSG_FRK, philo);
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
		writer(MSG_FRK, philo);
		pthread_mutex_lock(philo->lfork);
		if (get_death(philo->data))
			return (pthread_mutex_unlock(philo->lfork),
				pthread_mutex_unlock(philo->rfork), -1);
	}
	return (1);
}

int	p_eat(t_philo *philo)
{
	if (take_forks(philo) == -1)
		return (-1);
	writer(MSG_FRK, philo);
	if (get_death(philo->data))
		return (pthread_mutex_unlock(philo->rfork),
			pthread_mutex_unlock(philo->lfork), -1);
	writer(MSG_EAT, philo);
	pthread_mutex_lock(&philo->m_mutex);
	philo->lmeal = get_time();
	pthread_mutex_unlock(&philo->m_mutex);
	ft_sleep(philo->data, get_t_eat(philo->data));
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	return (1);
}
