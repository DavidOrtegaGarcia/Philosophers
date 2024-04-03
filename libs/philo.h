/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:56 by daortega          #+#    #+#             */
/*   Updated: 2024/04/03 17:42:24 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>

/*--------------STRUCTS--------------*/
typedef struct s_data
{
	int	n_philo;
	int t_death;
	int	t_eat;
	int t_sleep;
	int n_eats;
}	t_data;

/*--------------HEADERS--------------*/
t_data	fill_data(int argc, char *argv[]);
int		atoi(char *str);
void	print_data(t_data data);
#endif