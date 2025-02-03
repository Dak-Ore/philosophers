/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:51:34 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/04 00:40:54 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_end(t_philo *philo, char *msg)
{
	long	time;

	time = ft_get_time();
	if (philo)
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %d %s\n", time, philo->nb, msg);
		pthread_mutex_unlock(&philo->table->print);
	}
	else
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%ld %s\n", time, msg);
		pthread_mutex_unlock(&philo->table->print);
	}
}

int	check_all_eat(t_table *table)
{
	int	i;
	int	end;

	pthread_mutex_lock(&table->end);
	end = table->is_end;
	pthread_mutex_unlock(&table->end);
	if (end)
		return (0);
	i = -1;
	if (table->nb_eat == -2)
		return (1);
	while (++i < table->nb_philo)
	{
		pthread_mutex_lock(&table->philos[i]->eat_status);
		if (table->philos[i]->nb_eat < table->nb_eat)
			return (pthread_mutex_unlock(&table->philos[i]->eat_status), 1);
		pthread_mutex_unlock(&table->philos[i]->eat_status);
	}
	pthread_mutex_lock(&table->end);
	table->is_end = 1;
	pthread_mutex_unlock(&table->end);
	print_end(NULL, "Simulation ended because everyone eat enough\n");
	return (0);
}

void	*endgame(t_table *table)
{
	int	i;

	while (check_all_eat(table))
	{
		i = -1;
		while (++i < table->nb_philo)
		{
			pthread_mutex_lock(&table->philos[i]->eat_status);
			if (ft_get_time() - table->philos[i]->last_eat > table->time_die)
			{
				pthread_mutex_lock(&table->end);
				table->is_end = 1;
				pthread_mutex_unlock(&table->end);
				print_end(table->philos[i], "died");
				pthread_mutex_unlock(&table->philos[i]->eat_status);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philos[i]->eat_status);
		}
		usleep(1000);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	if (philo->nb % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_printph(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_printph(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_printph(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_printph(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->eat_status);
	philo->last_eat = ft_get_time();
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->eat_status);
	ft_printph(philo, "is eating");
	sleep_ms(philo->table->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		status;

	philo = (t_philo *)arg;
	status = 0;
	if (philo->table->nb_philo == 1)
		return (ft_printph(philo, "has taken a fork"), NULL);
	while (status == 0)
	{
		eat(philo);
		ft_printph(philo, "is sleeping");
		sleep_ms(philo->table->time_sleep);
		ft_printph(philo, "is thinking");
		pthread_mutex_lock(&philo->table->end);
		status = philo->table->is_end;
		pthread_mutex_unlock(&philo->table->end);
	}
	return (NULL);
}
