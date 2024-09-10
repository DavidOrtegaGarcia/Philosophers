/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:43:31 by daortega          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:34 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

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

static int	take_forks(t_philo *philo)
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
	return (1);
}

int	p_eat(t_philo *philo)
{
	if (take_forks(philo) == -1)
		return (-1);
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
