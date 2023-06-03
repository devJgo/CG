/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:21:17 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 17:21:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHADER_H__
#define __SHADER_H__

#include "common.h"

CLASS_PTR(Shader);

class Shader
{
public:
	static ShaderUPtr CreateFromFile(const std::string &filename,
									 GLenum shaderType);

	~Shader();
	uint32_t Get() const { return m_shader; }

private:
	Shader() {}
	bool LoadFile(const std::string &filename, GLenum shaderType);
	uint32_t m_shader{0};
};

#endif // __SHADER_H__
