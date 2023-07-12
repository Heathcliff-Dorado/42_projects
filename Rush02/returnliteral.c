/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returnliteral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmesropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:02:01 by tmesropo          #+#    #+#             */
/*   Updated: 2022/07/10 22:02:15 by tmesropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*returnliteral(char *src)
{
	char	*dest;
	int		i;
	int		k;
	int		w;

	i = 0;
	k = 0;
	w = 0;
	while (src[i] != ':')
		i++;
	i++;
	while (src[i] == ' ')
		i++;
	k = i;
	while (src[k] != '\0')
	{
		k++;
	}
	dest = malloc(k - i + 2);
	while (src[i] != '\0')
	{
		dest[w] = src[i];
		i++;
		w++;
	}
	dest[w+1] = '\0';
	return (dest);
}
