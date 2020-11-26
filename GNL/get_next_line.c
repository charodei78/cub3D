/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:46:45 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/20 16:02:00 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_check_line(char **line, char **res, int mode)
{
	char			*tmp_line;

	if (!line || !*line)
		return (0);
	if ((tmp_line = ft_strchr(*line, '\n')))
		*tmp_line = 0;
	if (!(*res = ft_strjoin(*res, *line)))
		return (-1);
	if (tmp_line)
		if (!(tmp_line = ft_strdup(tmp_line + 1)))
			return (-1);
	if (!mode)
		free(*line);
	if (tmp_line || !mode)
		*line = tmp_line;
	return (tmp_line ? 1 : 0);
}

int					ft_find_elem(int fd, t_list **start,
	t_list **res, char **line)
{
	t_list			*tmp_list;

	if (!(tmp_list = *start))
	{
		*start = ft_create_elem(fd, NULL, NULL);
		*res = *start;
		return (*res ? 0 : -1);
	}
	while (tmp_list)
	{
		if (tmp_list->fd == fd)
		{
			*res = tmp_list;
			return (ft_check_line(&tmp_list->left, line, 0));
		}
		if (tmp_list->next)
			tmp_list = tmp_list->next;
		else
		{
			tmp_list->next = ft_create_elem(fd, NULL, tmp_list);
			*res = tmp_list->next;
			return (*res ? 0 : -1);
		}
	}
	return (-1);
}

int					gnl(t_list *node, char *buf, char **line)
{
	int				res;

	while ((res = read(node->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		if ((res = ft_check_line(&buf, line, 1)))
		{
			if (res != -1)
			{
				if (!(node->left = ft_strdup(buf)))
				{
					free(*line);
					*line = 0;
					res = -1;
				}
				free(buf);
			}
			return (res);
		}
	}
	return (res);
}

int					clear_node(int res_code, t_list **start, t_list *node)
{
	if (node)
	{
		if (node->left && res_code < 1)
		{
			free(node->left);
			node->left = 0;
		}
		if (!node->left)
		{
			if (node->prev)
				node->prev->next = node->next;
			else
				*start = node->next;
			if (node->next)
				node->next->prev = node->prev;
			if (node == *start)
				*start = 0;
			free(node);
		}
	}
	return (res_code);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*fd_list;
	t_list			*cur_list;
	char			*buf;
	char			res_code;

	if (!fd_list)
		fd_list = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, 0, 0) == -1)
		return (-1);
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (!(*line = ft_strdup("")))
	{
		free(buf);
		return (-1);
	}
	res_code = ft_find_elem(fd, &fd_list, &cur_list, line);
	if (res_code == 0)
		res_code = gnl(cur_list, buf, line);
	free(buf);
	if (*line && res_code == -1)
		free(*line);
	return (clear_node(res_code, &fd_list, cur_list));
}
