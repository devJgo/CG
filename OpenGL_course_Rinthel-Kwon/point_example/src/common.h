/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:57:39 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 19:30:21 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COMMON_H__
#define __COMMON_H__

#include <memory>
#include <string>
#include <optional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#define CLASS_PTR(klassName)                            \
	class klassName;                                    \
	using klassName##UPtr = std::unique_ptr<klassName>; \
	using klassName##Ptr = std::shared_ptr<klassName>;  \
	using klassName##WPtr = std::weak_ptr<klassName>;

std::optional<std::string> LoadTextFile(const std::string &filename);

#endif // __COMMON_H
