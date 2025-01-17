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
