/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:51:34 by rsebasti          #+#    #+#             */
/*   Updated: 2025/01/31 12:46:08 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*endgame(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		while (++i < table->nb_philo)
		{
			pthread_mutex_lock(&table->philos[i]->eat_status);
			if (ft_get_time() - table->philos[i]->last_eat > table->time_die)
			{
				ft_printph(table->philos[i], "died");
				pthread_mutex_lock(&table->end);
				table->is_end = 1;
				pthread_mutex_unlock(&table->end);
				pthread_mutex_unlock(&table->philos[i]->eat_status);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philos[i]->eat_status);
		}
		check_eat(table);
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
	usleep(philo->table->time_eat * 1000);
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
	while (!status)
	{
		eat(philo);
		ft_printph(philo, "is sleeping");
		usleep(philo->table->time_sleep * 1000);
		ft_printph(philo, "is thinking");
		pthread_mutex_lock(&philo->table->end);
		status = philo->table->is_end ;
		pthread_mutex_unlock(&philo->table->end);
	}
	return (NULL);
}
