/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmallawa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:35:16 by rmallawa          #+#    #+#             */
/*   Updated: 2022/12/24 18:02:08 by rmallawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_input	*input;
	t_philo	**philos;

	input = NULL;
	if (argc < 5 || argc > 6)
		return (print_error());
	input = set_input(argv);
	if (input == NULL)
		return (EXIT_FAILURE);
	else
	{
		philos = init_philos(true);
		if (philos == NULL || philos[0] == NULL)
		{
			printf("Error while creating philosophers\n");
			return (EXIT_FAILURE);
		}
		if (thread_creation(input, philos) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	reaper();
	return (EXIT_SUCCESS);
}
