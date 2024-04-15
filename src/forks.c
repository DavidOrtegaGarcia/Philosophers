/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:58:02 by daortega          #+#    #+#             */
/*   Updated: 2024/04/15 17:59:08 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(pthread_mutex_t *forks, t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		free(forks[i]);
		i++;
	}
}