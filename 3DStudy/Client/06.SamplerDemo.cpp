#include "pch.h"
#include "06.SamplerDemo.h"

#include "CameraScript.h"
#include "GeometryHelper.h"
#include "../Engine/Camera.h"

void SamplerDemo::Init()
{
	shader = make_shared<Shader> (L"05.Texture.fx");

	geometry = make_shared<Geometry<VertexTextureData>>();
	//GeometryHelper::CreateQuad(geometry);
	//GeometryHelper::CreateCube(geometry);
	//GeometryHelper::CreateSphere(geometry);
	GeometryHelper::CreateGrid(geometry,10,10);

	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());

	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());

	m_pCamera = make_shared<GameObject>();
	m_pCamera->GetOrAddTransform();
	m_pCamera->AddComponent(make_shared<Camera>());
	m_pCamera->AddComponent(make_shared<CameraScript>());
	m_pCamera->GetTransform()->SetPosition(Vec3(0, 0, -10));

	m_pTexture = RESOURCES->Load<Texture>(L"Veigar", L"..\\Resources\\Textures\\veigar.JPG");
}

void SamplerDemo::Update()
{
	m_pCamera->Update();
}

void SamplerDemo::Render()
{
	shader->GetMatrix("World")->SetMatrix((float*)&world);
	shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);
	shader->GetSRV("Texture0")->SetResource(m_pTexture->GetComPtr().Get());

	enum ADRESS_VALUE
	{
		ADDRESS_WARP = 0,
		ADDRESS_MIRROR = 1,
		ADDRESS_CLAMP = 2,
		ADDRESS_BORDER = 3,
	};

	shader->GetScalar("Address")->SetInt(ADDRESS_WARP);

	uint32 stride = vertexBuffer->GetStride();
	uint32 offset = vertexBuffer->GetOffset();
	DC->IASetVertexBuffers(0, 1, vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);

	DC->IASetIndexBuffer(indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, 0, indexBuffer->GetCount(),0,0);
}
