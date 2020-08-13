/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:47:06 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/29 01:45:29 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		cntsymbol(char *s, char c)
{
	int cnt;

	if (*s == c || *s == '\0')
		cnt = 0;
	else
		cnt = 1;
	while (*(s + 1) && *s)
	{
		if (*s == c && *(s + 1) != c)
			cnt++;
		s++;
	}
	return (cnt);
}

static void		get_params(char **av, t_fdf **map)
{
	int		fd;
	int		check;
	char	*line;

	fd = open(av[1], O_RDONLY, 0);
	while (ft_get_next_line(fd, &line))
	{
		check = cntsymbol(line, ' ');
		if ((*map)->width != 0 && (*map)->width != check)
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			exit(1);
		}
		if (check != 0)
			(*map)->width = check;
		(*map)->height += 1;
		free(line);
	}
	close(fd);
}

void			get_map(char **av, int w, int h, t_fdf *map)
{
	char	*line;
	int		fd;
	int		i;
	int		j;
	char	**str;

	fd = open(av[1], O_RDONLY, 0);
	i = 0;
	map->map = ft_memalloc((h + 1) * sizeof(int*));
	while (ft_get_next_line(fd, &line))
	{
		j = 0;
		*(map->map + i) = ft_memalloc((w + 1) * sizeof(int));
		str = ft_strsplit(line, ' ');
		while (str[j] != NULL)
		{
			*(*(map->map + i) + j) = ft_atoi(str[j]);
			free(str[j]);
			j++;
		}
		*(*(map->map + i++) + j) = 0;
		free(str);
		free(line);
	}
	close(fd);
}

t_fdf			*read_fdf(char **av)
{
	t_fdf	*map;

	map = malloc(sizeof(t_fdf));
	map->height = 0;
	map->width = 0;
	get_params(av, &map);
	get_map(av, map->width, map->height, map);
	return (map);
}
