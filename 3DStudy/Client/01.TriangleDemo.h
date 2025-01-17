#pragma once
class TriangleDemo:public IExecute
{
public:
	void Init() override;
	void Update() override;
	void Render() override;

private:
	shared_ptr<Shader> shader;
	vector<VertexData>  vertices;
	shared_ptr<VertexBuffer> buffer;
};

