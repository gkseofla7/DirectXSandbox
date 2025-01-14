﻿#pragma once

#include <directxtk/SimpleMath.h>

namespace hlab {

using DirectX::SimpleMath::Matrix;
using DirectX::SimpleMath::Vector3;

class Camera {
  public:
    Camera() { UpdateViewDir(); }

    Matrix GetViewRow();
    Matrix GetProjRow();
    Vector3 GetEyePos();

    void UpdateViewDir();
    void UpdateKeyboard(const float dt, bool const keyPressed[256]);
    void UpdateMouse(float mouseNdcX, float mouseNdcY);
    void MoveForward(float dt);
    void MoveRight(float dt);
    void MoveUp(float dt);
    void SetAspectRatio(float aspect);
    Vector3 GetUpVector() { return m_upDir; }
    Vector3 GetViewDir() { return m_viewDir; }

  public:
    bool m_useFirstPersonView = false;
    Vector3 m_position = Vector3(0.275514f, 0.461257f, 0.0855238f);
    Vector3 m_viewDir = Vector3(0.0f, 0.0f, 1.0f);
  private:

    Vector3 m_upDir = Vector3(0.0f, 1.0f, 0.0f);
    Vector3 m_rightDir = Vector3(1.0f, 0.0f, 0.0f);

    // roll, pitch, yaw
    // https://en.wikipedia.org/wiki/Aircraft_principal_axes
    float m_yaw = -0.019635f, m_pitch = -0.120477f;

    float m_speed = 3.0f; // 움직이는 속도

    // 프로젝션 옵션도 카메라 클래스로 이동
    float m_projFovAngleY = 90.0f;
    float m_nearZ = 0.01f;
    float m_farZ = 100.0f;
    float m_aspect = 16.0f / 9.0f;
    bool m_usePerspectiveProjection = true;
};

} // namespace hlab
