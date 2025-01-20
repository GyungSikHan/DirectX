#include "pch.h"
#include "GeometryHelper.h"

void GeometryHelper::CreateQuad(shared_ptr<Geometry<VertexColorData>> geometry, Color color)
{
	vector<VertexColorData> vertexData;
	vertexData.resize(4);

	vertexData[0].position = Vec3(-0.5f, -0.5f, 0.0f);
	vertexData[0].color = color;
	vertexData[1].position = Vec3(-0.5f, 0.5f, 0.0f);
	vertexData[1].color = color;
	vertexData[2].position = Vec3(0.5f, -0.5f, 0.0f);
	vertexData[2].color = color;
	vertexData[3].position = Vec3(0.5f, 0.5f, 0.0f);
	vertexData[3].color = color;
	geometry->SetVertices(vertexData);

	vector<uint32> indices = { 0,1,2,2,1,3 };
	geometry->SetIndices(indices);
}

void GeometryHelper::CreateQuad(shared_ptr<Geometry<VertexTextureData>> geometry)
{
	vector<VertexTextureData> vertexData;
	vertexData.resize(4);

	vertexData[0].position = Vec3(-0.5f, -0.5f, 0.0f);
	vertexData[0].uv = Vec2(0.0f,1.0f);
	vertexData[1].position = Vec3(-0.5f, 0.5f, 0.0f);
	vertexData[1].uv = Vec2(0.0f, 0.0f);
	vertexData[2].position = Vec3(0.5f, -0.5f, 0.0f);
	vertexData[2].uv = Vec2(1.0f,1.0f);
	vertexData[3].position = Vec3(0.5f, 0.5f, 0.0f);
	vertexData[3].uv = Vec2(1.0f,0.0f);
	geometry->SetVertices(vertexData);

	vector<uint32> indices = { 0,1,2,2,1,3 };
	geometry->SetIndices(indices);
}

void GeometryHelper::CreateCube(shared_ptr<Geometry<VertexTextureData>> geometry)
{
}

void GeometryHelper::CreateSphere(shared_ptr<Geometry<VertexTextureData>> geometry)
{
}

void GeometryHelper::CreateGrid(shared_ptr<Geometry<VertexTextureData>> geometry)
{
}
