/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 19:38:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include "common.h"
#include "shader.h"

CLASS_PTR(Program)
class Program {
   public:
	static ProgramUPtr Create(const std::vector<ShaderPtr>& shaders);

	~Program();
	uint32_t Get() const { return m_program; }

   private:
	Program() {}
	bool Link(const std::vector<ShaderPtr>& shaders);
	uint32_t m_program{0};
};

#endif	// __PROGRAM_H__
