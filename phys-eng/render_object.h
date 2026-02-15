#pragma once

#include <memory>
#include "mesh.h"
#include "shader.h"

class RenderObject {
public:

	std::shared_ptr<Mesh> mesh;
	std::shared_ptr <Shader> shader;

	RenderObject(
		std::shared_ptr<Mesh> mesh,
		std::shared_ptr <Shader> shader)
		: mesh(mesh), shader(shader){}
};