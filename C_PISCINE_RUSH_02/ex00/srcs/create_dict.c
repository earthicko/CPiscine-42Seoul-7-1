/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:56:35 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/01 19:56:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/ft.h"
#include "../includes/strtools.h"

t_entry	**build_dict(char *path)
{
	int		n_bytes;
	char	*raw_content;
	char	**lines;
	t_entry	**dict;

	n_bytes = get_file_size(path);
	if (n_bytes < 0)
		return (NULL);
	raw_content = read_file_to_str(path, n_bytes);
	if (!raw_content)
		return (NULL);
	lines = ft_split(raw_content, "\n");
	free(raw_content);
	if (!lines)
		return (NULL);
	dict = create_dict(lines);
	free_arr_str(lines);
	return (dict);
}

int	get_file_size(char *path)
{
	int		fd;
	char	c;
	int		size;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*read_file_to_str(char *path, int n_bytes)
{
	int		fd;
	char	*dict;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict = (char *)malloc(sizeof(char) * (n_bytes + 1));
	if (!dict)
		return (NULL);
	if (read(fd, dict, n_bytes) <= 0)
	{
		free(dict);
		return (NULL);
	}
	dict[n_bytes] = '\0';
	if (close(fd) == -1)
	{
		free(dict);
		return (NULL);
	}
	return (dict);
}

t_entry	**create_dict(char **lines)
{
	t_entry	**dict;
	int		idx;
	int		n_entries;

	idx = 0;
	n_entries = 0;
	while (lines[idx])
	{
		if (check_entry(lines[idx]))
			n_entries++;
		else
			return (NULL);
		idx++;
	}
	dict = (t_entry **)malloc(sizeof(t_entry *) * (n_entries + 1));
	if (!dict)
		return (NULL);
	if (create_entries(lines, dict) < 0)
	{
		free(dict);
		return (NULL);
	}
	return (dict);
}
