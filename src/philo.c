/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/08/22 16:04:56 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

/*void	free_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->n_philo)
	{
		free(&philos[i]);
		i++;
	}
}

static void	routine(t_philo *philo)
{
	while(1)
	{
		//eat
		//sleep 
		//think
	}
}

t_philo	*create_philos(t_philo *philos)
{
	int	i;

	i = 0;
	philos->data->t_start = get_time();
	while (i < philos->data->n_philo)
	{
		if (pthread_create(&philos[i].pthread, NULL, 
			&routine, &philos[i]) != 0)
			return (NULL);
		i++;
	}
	/////monitor
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
		i++;
	}
	return (philos);
}*/
