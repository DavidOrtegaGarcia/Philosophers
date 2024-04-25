/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/04/24 15:56:48 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

void	free_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->n_philo)
	{
		free(philos[i]);
		i++;
	}
}

static void	*routine(t_philo *philo)
{
	while(philo->data->death)
	{
		
	}
}

t_philo	*create_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->n_philo)
	{
		if (philos[i].pthread = pthread_create(philos[i].pthread, NULL, 
			&routine, &philos[i]) != 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < philos->data->n_philo)
	{
		pthread_join(&philos[i], NULL);
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
		i++;
	}
	return (philos);
}
