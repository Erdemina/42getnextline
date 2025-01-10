/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:54 by eulutas           #+#    #+#             */
/*   Updated: 2025/01/10 15:50:54 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int finder(const char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *strjoin(char *line, char *buffer)
{
	size_t i;
	size_t j;
	char *result;

	if (!line)
	{
		line = malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buffer)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(line) + 1));
	if (!result)
		return (0);
	i = -1;
	if (line)
		while (line[++i])
			result[i] = line[i];
	j = 0;
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	free(line);
	return (result);
}

char *getbefore(char *str)
{
	char *res;
	int i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *getafter(char *str)
{
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}