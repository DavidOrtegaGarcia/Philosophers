/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/04/10 14:44:45 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

static void	*action(t_data *data)
{
	printf("Funciona\n");
}

t_philo	*fill_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		if (philos[i].pthread = pthread_create(philos[i].pthread, NULL, 
			&action, data) != 0)
			return (NULL);
		pthread_join(philos[i].pthread, NULL);
		i++;
	}
	return (philos);
}
