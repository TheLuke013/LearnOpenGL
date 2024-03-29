#define ASSERT(x) if (!(x)) std::abort();
#define GLCall(x) { GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__)) }

#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include <GL/glew.h>
#include <iostream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

};

#endif
