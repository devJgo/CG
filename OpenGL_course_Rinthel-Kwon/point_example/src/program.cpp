/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:53 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 19:39:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

ProgramUPtr Program::Create(const std::vector<ShaderPtr>& shaders) {
	auto program = ProgramUPtr(new Program());
	if (!program->Link(shaders))
		return nullptr;
	return std::move(program);
}

bool Program::Link(const std::vector<ShaderPtr>& shaders) {
	m_program = glCreateProgram();
	for (auto& shader : shaders)
		glAttachShader(m_program, shader->Get());
	glLinkProgram(m_program);
	int success = 0;
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[1024];
		glGetProgramInfoLog(m_program, 1024, nullptr, infoLog);
		SPDLOG_ERROR("failed to link program: {}", infoLog);
		return false;
	}
	return true;
}

Program::~Program() {
	if (m_program) {
		glDeleteProgram(m_program);
	}
}
