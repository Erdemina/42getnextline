/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulutas <eulutas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:42 by eulutas           #+#    #+#             */
/*   Updated: 2025/01/10 15:50:42 by eulutas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	char *str_buf;
	struct s_list *next;
} t_list;

int found_newline(t_list *list);
t_list *find_last_node(t_list *list);
char *get_line(t_list *list);
void copy_str(t_list *list, char *str);
int len_to_newline(t_list *list);
void polish_list(t_list **list);
char *get_next_line(int fd);
void dealloc(t_list **list, t_list *clean_node, char *buf);
void create_list(t_list **list, int fd);

#endif