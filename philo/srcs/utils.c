/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:06:39 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/02 17:31:50 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_ms(long duration)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() < start + duration)
		usleep(500);
}

int	ft_printph(t_philo *philo, char *msg)
{
	int		stop;
	long	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->table->end);
	stop = philo->table->is_end;
	if (stop)
		return (pthread_mutex_unlock(&philo->table->end), 1);
	pthread_mutex_unlock(&philo->table->end);
	pthread_mutex_lock(&philo->table->print);
	printf("%ld %d %s\n", time, philo->nb, msg);
	pthread_mutex_unlock(&philo->table->print);
	return (1);
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
