#pragma once
#include "Geometry.h"

class TextureDemo : public IExecute
{
public:
	void Init() override;
	void Update() override;
	void Render() override;

private:
	shared_ptr<Shader> shader;
	//�ؿ� 3���� Mesh�� ������ ����
	shared_ptr<Geometry<VertexTextureData>> geometry;
	shared_ptr<VertexBuffer> vertexBuffer;
	shared_ptr<IndexBuffer> indexBuffer;

	Matrix world = Matrix::Identity;

	shared_ptr<GameObject> m_pCamera;
	shared_ptr<Texture> m_pTexture;
};

