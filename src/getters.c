/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:13:37 by daortega          #+#    #+#             */
/*   Updated: 2024/09/10 16:28:03 by daortega         ###   ########.fr       */
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

int	get_t_death(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->getter);
	result = data->t_death;
	pthread_mutex_unlock(&data->getter);
	return (result);
}

int	get_t_eat(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->getter);
	result = data->t_eat;
	pthread_mutex_unlock(&data->getter);
	return (result);
}

int	get_t_sleep(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->getter);
	result = data->t_sleep;
	pthread_mutex_unlock(&data->getter);
	return (result);
}

int	get_n_eats(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->getter);
	result = data->n_eats;
	pthread_mutex_unlock(&data->getter);
	return (result);
}

bool	get_death(t_data *data)
{
	bool	result;

	pthread_mutex_lock(&data->lock);
	result = data->death;
	pthread_mutex_unlock(&data->lock);
	return (result);
}
