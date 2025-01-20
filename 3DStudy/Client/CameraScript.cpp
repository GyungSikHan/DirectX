#include "pch.h"
#include "CameraScript.h"

void CameraScript::Start()
{
	MonoBehaviour::Start();
}

void CameraScript::Update()
{
	MonoBehaviour::Update();

	float dt = TIME->GetDeltaTime();

	Vec3 pos = GetTransform()->GetPosition();

	if (INPUT->GetButton(KEY_TYPE::W))
		pos += GetTransform()->GetLook() * m_fSpeed * dt;
	if (INPUT->GetButton(KEY_TYPE::S))
		pos -= GetTransform()->GetLook() * m_fSpeed * dt;
	if (INPUT->GetButton(KEY_TYPE::A))
		pos -= GetTransform()->GetRight() * m_fSpeed * dt;
	if (INPUT->GetButton(KEY_TYPE::D))
		pos += GetTransform()->GetRight() * m_fSpeed * dt;

	GetTransform()->SetPosition(pos);
	
	Vec3 rotation = GetTransform()->GetLocalRotation();

	if (INPUT->GetButton(KEY_TYPE::Q))
		rotation.x += dt * 0.5f;
	if (INPUT->GetButton(KEY_TYPE::E))
		rotation.x -= dt * 0.5f;
	if (INPUT->GetButton(KEY_TYPE::Z))
		rotation.y += dt * 0.5f;
	if (INPUT->GetButton(KEY_TYPE::C))
		rotation.y -= dt * 0.5f;

	GetTransform()->SetLocalRotation(rotation);
}
