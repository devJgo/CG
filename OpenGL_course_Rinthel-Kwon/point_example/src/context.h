/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:42:29 by jgo               #+#    #+#             */
/*   Updated: 2023/06/03 19:42:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "common.h"
#include "program.h"
#include "shader.h"

CLASS_PTR(Context)
class Context {
   public:
	static ContextUPtr Create();
	void Render();

   private:
	Context() {}
	bool Init();
	ProgramUPtr m_program;
};

#endif	// __CONTEXT_H__
