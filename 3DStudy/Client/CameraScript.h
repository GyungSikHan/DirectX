#pragma once
#include "MonoBehaviour.h"

class CameraScript:public MonoBehaviour
{
public:
	void Start() override;
	void Update() override;

	float m_fSpeed = 10.0f;
};

