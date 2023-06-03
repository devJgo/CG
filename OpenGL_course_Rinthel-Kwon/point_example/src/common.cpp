/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:05:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 17:05:46 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <fstream>
#include <sstream>

std::optional<std::string> LoadTextFile(const std::string &filename)
{
	std::ifstream fin(filename);
	if (!fin.is_open())
	{
		SPDLOG_ERROR("failed to open file: {}", filename);
		return {};
	}
	std::stringstream text;
	text << fin.rdbuf();
	return text.str();
}
