#pragma once
#include "BaseComponent.h"
#include <set>
#include <DirectXMath.h>
using namespace DirectX;

#define Rad2Deg 57.2957795130f
#define Deg2Rad 0.0174532925f

namespace VECTOR3
{
	const XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	const XMVECTOR down = XMVectorSet(0.0f, -1.0f, 0.0f, 0.0f);
	const XMVECTOR forward = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
	const XMVECTOR back = XMVectorSet(0.0f, 0.0f, -1.0f, 0.0f);
	const XMVECTOR right = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	const XMVECTOR left = XMVectorSet(-1.0f, 0.0f, 0.0f, 0.0f);
}

class DXGameObject;
class DXTransform : public BaseComponent
{
private:
	DXTransform* parent;
	std::set<DXTransform*> childs;

	XMFLOAT3 position;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;

	XMMATRIX translationMatrix;
	XMMATRIX rotationMatrix;
	XMMATRIX scaleMatrix;

	XMMATRIX worldMatrix;

	XMVECTOR up;
	XMVECTOR forward;
	XMVECTOR right;

public:
	DXTransform(DXGameObject* gameObject);

	const DXGameObject* GameObject() const;

	void SetParent(DXTransform* parent);

	void SetLookAt(XMFLOAT3 lookAtPos);

	void SetPosition(const XMFLOAT3& position);
	void SetLocalRotation(const XMFLOAT3& rotation);
	void SetLocalScale(const XMFLOAT3& scale);

	void AdjustPosition(const XMFLOAT3& value);
	void AdjustPosition(const XMVECTOR& value);
	void AdjustRotation(const XMFLOAT3& value);
	void AdjustRotation(const XMVECTOR& value);

	const XMVECTOR& GetPosition() const;
	const XMVECTOR& GetScale() const;

	const XMMATRIX& GetTranslationMatrix() const;
	const XMMATRIX& GetRotationMatrix() const;
	const XMMATRIX& GetScaleMatrix() const;
	const XMMATRIX& GetWorldMatrix() const;

	const XMVECTOR& GetUp() const;
	const XMVECTOR& GetForward() const;
	const XMVECTOR& GetRight() const;

private:
	void UpdateTranslationMatrix();
	void UpdateRotationMatrix();
	void UpdateScaleMatrix();
	void UpdateWorldMatrix();

	void AddChild(DXTransform* child);
	void RemoveChild(DXTransform* child);
};