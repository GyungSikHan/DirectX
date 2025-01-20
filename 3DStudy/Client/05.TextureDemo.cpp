#include "pch.h"
#include "05.TextureDemo.h"

#include "CameraScript.h"
#include "GeometryHelper.h"
#include "../Engine/Camera.h"

void TextureDemo::Init()
{
	shader = make_shared<Shader> (L"05.Texture.fx");

	geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateQuad(geometry);

	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());

	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());

	m_pCamera = make_shared<GameObject>();
	m_pCamera->GetOrAddTransform();
	m_pCamera->AddComponent(make_shared<Camera>());
	m_pCamera->AddComponent(make_shared<CameraScript>());

	m_pCamera->GetTransform()->SetPosition(Vec3(0, 0, -10));

	m_pTexture = RESOURCES->Load<Texture>(L"Veigar", L"..\\Resources\\Textures\\veigar.jpg");
}

void TextureDemo::Update()
{
	m_pCamera->Update();
}

void TextureDemo::Render()
{
	shader->GetMatrix("World")->SetMatrix((float*)&world);
	shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);
	shader->GetSRV("Texture0")->SetResource(m_pTexture->GetComPtr().Get());

	uint32 stride = vertexBuffer->GetStride();
	uint32 offset = vertexBuffer->GetOffset();
	DC->IASetVertexBuffers(0, 1, vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);

	DC->IASetIndexBuffer(indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, 0, indexBuffer->GetCount());
}
