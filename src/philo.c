/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:28:52 by daortega          #+#    #+#             */
/*   Updated: 2024/04/08 16:16:30 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

static void *action(t_data data);


pthread_t	*fill_philos(pthread_t **philos, t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		philos[i] = pthread_create(*philos[i], NULL, action(data),);
		i++;
	}
}