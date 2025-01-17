#include "pch.h"
#include "02.QuadDemo.h"
#include "GeometryHelper.h"
 
void QuadDemo::Init()
{
	shader = make_shared<Shader >(L"02.Quad.fx");
	geometry = make_shared<Geometry<VertexColorData>>();
	GeometryHelper::CreateQuad(geometry, Color(1.0f, 1.0f, 0.0f, 1.0f));

	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());

	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());
}

void QuadDemo::Update()
{
}

void QuadDemo::Render()
{
	uint32 stride = vertexBuffer->GetStride();
	uint32 offset = vertexBuffer->GetOffset();
	DC->IASetVertexBuffers(0, 1, vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);

	DC->IASetIndexBuffer(indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);
	shader->DrawIndexed(0, 1, indexBuffer->GetCount(), 0, 0);
}
