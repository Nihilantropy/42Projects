/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:04:35 by crea              #+#    #+#             */
/*   Updated: 2024/04/16 16:02:20 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**find_total_path(char **envp)
{
	// Dichiaro la path totale, ovvero tutto ciò che si trova dopo la
	// variabile PATH= nell'ambiente envp
	char	**total_path;
	int		i;

	i = 0;
	// Itero finchè non trovo la variabile PATH=
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	// Splitto i vari percorsi delle cartelle, che sono separati dai ':'
	// Es. /usr/bin:/usr/sbin:/ etc...
	total_path = ft_split(envp[i] + 5, ':');
	return (total_path);
}
