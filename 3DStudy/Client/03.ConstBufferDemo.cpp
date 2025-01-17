#include "pch.h"
#include "03.ConstBufferDemo.h"
#include "GeometryHelper.h"

void ConstBufferDemo::Init()
{
	shader = make_shared<Shader> (L"03.ConstBuffer.fx");

	geometry = make_shared<Geometry<VertexColorData>>();
	GeometryHelper::CreateQuad(geometry, Color(1.0f, 0.0f, 0.0f,1.0f));

	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());

	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());
}

void ConstBufferDemo::Update()
{
	float deltaTime = TIME->GetDeltaTime();

	//������Ʈ �Լ����� � Ư������ ���� ���� ��ǻ�͸��� �ӵ��� �޶� Update ȣ�� �ֱⰡ �޶� ��ǻ�� ��縶�� �ӵ��� �޶��� ���̴�
	//�׷��� �̸� �ذ��ϱ� ���� deltaTime�� ������� �Ѵ�
	if (INPUT->GetButton(KEY_TYPE::A))
		translation.x -= 3.0f * deltaTime;
	if(INPUT->GetButton(KEY_TYPE::D))
		translation.x += 3.0f * deltaTime;
	if(INPUT->GetButton(KEY_TYPE::W))
		translation.y += 3.0f * deltaTime;
	if(INPUT->GetButton(KEY_TYPE::S))
		translation.y -= 3.0f * deltaTime;


	//SRT
	world = Matrix::CreateTranslation(translation);
}

void ConstBufferDemo::Render()
{
	shader->GetMatrix("World")->SetMatrix((float*)&world);
	shader->GetMatrix("View")->SetMatrix((float*)&view);
	shader->GetMatrix("Projection")->SetMatrix((float*)&projection);

	uint32 stride = vertexBuffer->GetStride();
	uint32 offset = vertexBuffer->GetOffset();
	DC->IASetVertexBuffers(0, 1, vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);

	DC->IASetIndexBuffer(indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, 0, indexBuffer->GetCount());
}
