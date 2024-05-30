/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:29:24 by alcarden          #+#    #+#             */
/*   Updated: 2024/05/29 13:31:32 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>

void ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}
