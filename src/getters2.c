/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:32:46 by daortega          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:08 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

long long	get_l_meal(t_philo *philo)
{
	long long	result;

	pthread_mutex_lock(&philo->m_mutex);
	result = philo->lmeal;
	pthread_mutex_unlock(&philo->m_mutex);
	return (result);
}

int	get_n_meals(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->m_mutex);
	result = philo->nmeals;
	pthread_mutex_unlock(&philo->m_mutex);
	return (result);
}

long long	get_t_start(t_data *data)
{
	long long	result;

	pthread_mutex_lock(&data->lock);
	result = data->t_start;
	pthread_mutex_unlock(&data->lock);
	return (result);
}
