/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:04:46 by donghyle          #+#    #+#             */
/*   Updated: 2022/05/04 10:04:48 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**alloc_char_array_2(int rows, int cols)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * rows);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		arr[i] = (char *)malloc(sizeof(char) * cols);
		if (!arr[i])
		{
			j = 0;
			while (j < i)
				free(arr[j++]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

char	delete_char_array_2(char **arr, int n_rows)
{
	int	r;

	r = 0;
	while (r < n_rows)
	{
		free(arr[r]);
		r++;
	}
	free(arr);
	return (0);
}

int	**alloc_int_array_2(int rows, int cols)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(sizeof(int *) * rows);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		arr[i] = (int *)malloc(sizeof(int) * cols);
		if (!arr[i])
		{
			j = 0;
			while (j < i)
				free(arr[j++]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	delete_int_array_2(int **arr, int n_rows)
{
	int	r;

	r = 0;
	while (r < n_rows)
	{
		free(arr[r]);
		r++;
	}
	free(arr);
	return (0);
}
