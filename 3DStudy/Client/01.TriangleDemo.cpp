#include "pch.h"
#include "01.TriangleDemo.h"

void TriangleDemo::Init()
{
	shader = make_shared<Shader>(L"01.Triangle.fx");

	{
		vertices.resize(3);
		vertices[0].position = Vec3(-0.5f, 0.0f, 0.0f);
		vertices[1].position = Vec3(0.0f, 0.5f, 0.0f);
		vertices[2].position = Vec3(0.5f, 0.0f, 0.0f);
	}

	buffer = make_shared<VertexBuffer>();
	buffer->Create(vertices);
}

void TriangleDemo::Update()
{
}

void TriangleDemo::Render()
{
	uint32 stride = buffer->GetStride();
	uint32 offset = buffer->GetOffset();

	DC->IASetVertexBuffers(0, 1, buffer->GetComPtr().GetAddressOf(), &stride, &offset);

	shader->Draw(0, 1, buffer->GetCount());
}