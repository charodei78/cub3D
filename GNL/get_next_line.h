/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:46:50 by hheimerd          #+#    #+#             */
/*   Updated: 2020/08/27 21:26:38 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 	50

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	int				fd;
	char			*left;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list				*ft_create_elem(int fd, char *left, t_list *prev);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
int					ft_check_line(char **line, char **res, int mode);
int					ft_find_elem(int fd, t_list **start, t_list **res,
	char **line);
int					gnl(t_list *node, char *buf, char **line);
int					clear_node(int res_code, t_list **start, t_list *node);
int					get_next_line(int fd, char **line);
#endif
