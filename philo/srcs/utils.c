/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:06:39 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/29 19:09:01 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	putstr_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

int	ft_atoi_secure(const char *nptr)
{
	long	result;

	if (!nptr)
		return (-1);
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			return (-1);
	while (*nptr)
	{
		if (!(*nptr >= '0' || *nptr <= '9'))
			return (-1);
		result = result * 10 + (*(nptr++) - '0');
	}
	return ((int)result);
}

