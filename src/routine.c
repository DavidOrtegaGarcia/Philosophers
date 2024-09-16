/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:43:31 by daortega          #+#    #+#             */
/*   Updated: 2024/09/16 18:52:22 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

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
	writer(MSG_FRK, philo);
	return (1);
}

int	p_eat(t_philo *philo)
{
	if (take_forks(philo) == -1)
		return (-1);
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

t_philo	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	writer(MSG_FRK, philo);
	ft_sleep(philo->data, get_t_death(philo->data));
	pthread_mutex_unlock(philo->rfork);
	return (philo);
}

