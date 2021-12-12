/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfreixo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:38:45 by mfreixo-          #+#    #+#             */
/*   Updated: 2021/12/12 09:38:47 by mfreixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *str);
int		ft_newline(char *str);
char	*ft_save_buff(char *buffer, int pos);
int		ft_read(int fd, char *buffer);
char	*get_line(int fd);
char	*get_next_line(int fd);

#endif
