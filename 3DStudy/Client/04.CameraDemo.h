#pragma once
#include "Geometry.h"

class CameraDemo : public IExecute
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

	Vec3 translation = Vec3(0.0f, 0.0f, 0.0f);

	Matrix world = Matrix::Identity;

	shared_ptr<GameObject> m_pCamera;
};

