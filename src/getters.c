/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:13:37 by daortega          #+#    #+#             */
/*   Updated: 2024/04/29 16:49:57 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int get_t_death(t_data *data)
{
	int result;

	pthread_mutex_lock(&data->getter);
	result = data->t_death;
	pthread_mutex_unlock(&data->getter);
	return(result);
}

int get_t_eat(t_data *data)
{
	int result;

	pthread_mutex_lock(&data->getter);
	result = data->t_eat;
	pthread_mutex_unlock(&data->getter);
	return(result);
}

int get_t_sleep(t_data *data)
{
	int result;

	pthread_mutex_lock(&data->getter);
	result = data->t_sleep;
	pthread_mutex_unlock(&data->getter);
	return(result);
}

int get_n_eats(t_data *data)
{
	int result;
	
	pthread_mutex_lock(&data->getter);
	result = data->n_eats;
	pthread_mutex_unlock(&data->getter);
	return(result);
}

bool get_death(t_data *data)
{
	bool result;

	pthread_mutex_lock(&data->getter);
	result = data->death;
	pthread_mutex_unlock(&data->getter);
	return(result);
}

