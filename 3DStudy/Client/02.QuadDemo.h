#pragma once
#include "Geometry.h"

class QuadDemo :public IExecute
{
public:
	void Init() override;
	void Update() override;
	void Render() override;

private:
	shared_ptr<Shader> shader;
	shared_ptr<Geometry<VertexColorData>> geometry;
	shared_ptr<VertexBuffer> vertexBuffer;
	shared_ptr<IndexBuffer> indexBuffer;
};

