/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:08:08 by eahn              #+#    #+#             */
/*   Updated: 2024/10/25 16:54:59 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_rgb(char **line)
{
	int	rgb;
	int	f_comma;

	while (ft_isspace(**line))
		(*line)++;
	if (!ft_isdigit(**line))
		print_error("Invalid RGB value. Missing or incorrect value.\n");
	rgb = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	f_comma = 0;
	while (ft_isspace(**line) || **line == ',')
	{
		if (**line == ',')
		{
			if (f_comma)
				print_error("Invalid RGB value. Multiple commas.\n");
			f_comma = 1;
		}
		(*line)++;
	}
	if (!ft_isdigit(**line) && **line != '\0')
		print_error("Invalid RGB value. Missing or incorrect value.\n");
	return (rgb);
}

static void	assign_color(int *color, t_rgb rgb, char *str)
{
	if (*color != -1)
		print_error(str);
	*color = (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

static void	check_comma(char *line)
{
	int	c_comma;

	c_comma = 0;
	while (*line)
	{
		if (*line == ',')
			c_comma++;
		line++;
	}
	if (c_comma != 2)
		print_error("Invalid RGB value. Incorrect format.\n");
}

void	parse_color(t_map *map, char *line, char type)
{
	t_rgb	rgb;

	line += 2;
	while (ft_isspace(*line))
		line++;
	check_comma(line);
	rgb.r = extract_rgb(&line);
	rgb.g = extract_rgb(&line);
	rgb.b = extract_rgb(&line);
	if (!(rgb.r >= 0 && rgb.r <= 255) || !(rgb.g >= 0 && rgb.g <= 255)
		|| !(rgb.b >= 0 && rgb.b <= 255))
		print_error("RGB values must be between 0 ad 255.\n");
	if (type == 'F')
		assign_color(&map->f_color, rgb, "Floor color already set.\n");
	else if (type == 'C')
		assign_color(&map->c_color, rgb, "Ceiling color already set.\n");
	else
		print_error("Invalid color type.\n");
}
