/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:00:50 by daortega          #+#    #+#             */
/*   Updated: 2024/04/08 14:29:14 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/philo.h"

int	atoi(char *str)
{
	int i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{	
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}
