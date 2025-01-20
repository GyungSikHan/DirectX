#include "pch.h"
#include "04.CameraDeme.h"

#include "CameraScript.h"
#include "GeometryHelper.h"
#include "../Engine/Camera.h"

void CameraDemo::Init()
{
	shader = make_shared<Shader> (L"03.ConstBuffer.fx");

	geometry = make_shared<Geometry<VertexColorData>>();
	GeometryHelper::CreateQuad(geometry, Color(1.0f, 0.0f, 0.0f,1.0f));

	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());

	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());

	m_pCamera = make_shared<GameObject>();
	m_pCamera->GetOrAddTransform();
	m_pCamera->AddComponent(make_shared<Camera>());
	m_pCamera->AddComponent(make_shared<CameraScript>());

	m_pCamera->GetTransform()->SetPosition(Vec3(0, 0, -10));
}

void CameraDemo::Update()
{
	m_pCamera->Update();
}

void CameraDemo::Render()
{
	shader->GetMatrix("World")->SetMatrix((float*)&world);
	shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);

	uint32 stride = vertexBuffer->GetStride();
	uint32 offset = vertexBuffer->GetOffset();
	DC->IASetVertexBuffers(0, 1, vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);

	DC->IASetIndexBuffer(indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, 0, indexBuffer->GetCount());
}
