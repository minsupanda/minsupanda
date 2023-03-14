#pragma once
#include <DirectXMath.h>
using namespace DirectX;

enum class ComponentType { INVAILED, ACTION, RENDER };

class DXGameObject;
class BaseComponent abstract
{
protected:
    DXGameObject* owner;

public:
    BaseComponent(DXGameObject* owner) : owner(owner) { }
    virtual ~BaseComponent() { }

    virtual ComponentType GetType() { return ComponentType::INVAILED; }

    DXGameObject* GetGameObject() const { return owner; }

protected:
    virtual void Opertate() { }
};

class ActionComponent abstract : public BaseComponent
{
public:
    ActionComponent(DXGameObject* owner) : BaseComponent(owner) { }
    virtual ~ActionComponent() { }

    virtual ComponentType GetType() final { return ComponentType::ACTION; }

    void Update() { Opertate(); }

protected:
    virtual void Opertate() override { assert("Opertate must be overridden." && 0); }
};

class RenderComponent abstract : public BaseComponent
{
protected:
    XMMATRIX viewProjectionMatrix;

public:
    RenderComponent(DXGameObject* owner) : BaseComponent(owner)
    {
        viewProjectionMatrix = XMMatrixIdentity();
    }
    virtual ~RenderComponent() {}

    virtual ComponentType GetType() final { return ComponentType::RENDER; }

    void Draw(const XMMATRIX& viewProjectionMatrix)
    {
        this->viewProjectionMatrix = viewProjectionMatrix;
        Opertate();
    }

protected:
    virtual void Opertate() override { assert("Opertate must be overridden." && 0); }
};