
#include "helper.h"
#include "pointers.h"
#include "btBulletDynamicsCommon.h"
#include "world.h"
#include "rigidbody.h"

Nan::Persistent<v8::Function> mox::physics::World::constructor;

mox::physics::World::World()
{
  m_collisionConfiguration = std::make_shared<btDefaultCollisionConfiguration>();

  m_collisionDispatcher = std::make_shared<btCollisionDispatcher>(m_collisionConfiguration.get());

  m_dbvtBroadphase = std::make_shared<btDbvtBroadphase>();

  m_sequentialImpulseConstraintSolver =
    std::make_shared<btSequentialImpulseConstraintSolver>();

  m_discreteDynamicsWorld = std::make_shared<btDiscreteDynamicsWorld>(
    m_collisionDispatcher.get(),
    m_dbvtBroadphase.get(),
    m_sequentialImpulseConstraintSolver.get(),
    m_collisionConfiguration.get());

	m_discreteDynamicsWorld->setGravity(btVector3(0,-9.8,0));
}

mox::physics::World::~World()
{
}

void mox::physics::World::Init(v8::Local<v8::Object> namespc)
{
  DEFINE_FUNCTION_TEMPLATE("World", tpl);

  Nan::SetPrototypeMethod(tpl, "addRigidBody", addRigidBody);

  constructor.Reset(tpl->GetFunction());
  namespc->Set(Nan::New("World").ToLocalChecked(),
    tpl->GetFunction());
}

NAN_METHOD(mox::physics::World::New)
{
  ALLOW_ONLY_CONSTRUCTOR(info);
  World *obj = new World();
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(mox::physics::World::addRigidBody)
{
  CHECK_NUM_ARGUMENTS(info, 1);
  GET_SELF(mox::physics::World, self);

  if (!info[0]->IsUndefined()) {
    mox::physics::RigidBody *rigidBody =
      Nan::ObjectWrap::Unwrap<mox::physics::RigidBody>(info[0]->ToObject());

    btRigidBodyPtr btRigidBody = rigidBody->getRigidBody();
    self->m_discreteDynamicsWorld->addRigidBody(btRigidBody.get());
  }

}
