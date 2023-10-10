/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:29:33 by davidga2          #+#    #+#             */
/*   Updated: 2023/06/09 00:05:35 by davidga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **ptr)
{
	if (!*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_return;
	char	*old_stash;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	while (!ft_strchr(stash, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_return = read(fd, buffer, BUFFER_SIZE);
		old_stash = stash;
		stash = ft_strjoin_gnl(stash, buffer);
		ft_free(&old_stash);
		ft_free(&buffer);
		if (ft_strlen(stash) && read_return == 0)
			return (old_stash = ft_substr(stash, 0, -1),
				ft_free(&stash), old_stash);
		if (read_return <= 0)
			return (ft_free(&stash), NULL);
	}
	return (stash);
}

static char	*ft_clean_stash(char *stash)
{
	char	*ptr;
	size_t	pos;
	char	*cleaned_stash;

	ptr = ft_strchr(stash, '\n');
	pos = ft_strlen(stash) - ft_strlen(ptr) + 1;
	cleaned_stash = ft_substr(stash, pos, -1);
	free(stash);
	return (cleaned_stash);
}

static char	*ft_make_this_line(char *stash)
{
	char	*ptr;
	ssize_t	pos;
	char	*total_line;

	if (ft_strchr(stash, '\n'))
		ptr = ft_strchr(stash, '\n');
	else
		return (total_line = ft_substr(stash, 0, -1));
	pos = ft_strlen(stash) - ft_strlen(ptr) + 1;
	total_line = ft_substr(stash, 0, pos);
	return (total_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (0);
	line = ft_make_this_line(stash);
	if (!line)
		return (0);
	if (ft_strchr(line, '\n'))
		stash = ft_clean_stash(stash);
	else
		ft_free(&stash);
	return (line);
}
/*
int	main(void)
{
	//char path[] = "hola.txt";
	//char path[] = "letania.txt";
	char path[] = "dune.txt";
	//char path[] = "americanpie.txt";
	//char path[] = "breaklines.txt";
	//char path[] = "1char.txt";
	//char path[] = "variable_nls.txt";
	//char path[] = "one_line_no_nl.txt";
	//char path[] = giant_line.txt
	//char path[] = giant_line_nl.txt

	int fd = open(path, O_RDONLY);

	char *line;
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}

	system("leaks a.out");

//	for (int i = 1; i <= 8; i++)
//		printf("---Line value: '%s'---BL\n", get_next_line(fd));

	close(fd);
	return (0);
}*/
