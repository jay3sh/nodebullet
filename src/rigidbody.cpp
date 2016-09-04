
#include "helper.h"
#include "btBulletDynamicsCommon.h"
#include "pointers.h"
#include "rigidbody.h"

Nan::Persistent<v8::Function> mox::physics::RigidBody::constructor;

mox::physics::RigidBody::RigidBody()
{

}

mox::physics::RigidBody::~RigidBody()
{

}

void mox::physics::RigidBody::Init(v8::Local<v8::Object> namespc)
{
  DEFINE_FUNCTION_TEMPLATE("RigidBody", tpl);

  Nan::SetPrototypeMethod(tpl, "initBox", initBox);
  Nan::SetPrototypeMethod(tpl, "isBox", isBox);

  constructor.Reset(tpl->GetFunction());
  namespc->Set(Nan::New("RigidBody").ToLocalChecked(), tpl->GetFunction());

}

NAN_METHOD(mox::physics::RigidBody::New)
{
  ALLOW_ONLY_CONSTRUCTOR(info);
  RigidBody *obj = new RigidBody();
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(mox::physics::RigidBody::initBox)
{
  GET_SELF(mox::physics::RigidBody, self);
  CHECK_NUM_ARGUMENTS(info, 3);
  double dx = info[0]->IsUndefined() ? 0 : Nan::To<double>(info[0]).FromJust();
  double dy = info[1]->IsUndefined() ? 0 : Nan::To<double>(info[1]).FromJust();
  double dz = info[2]->IsUndefined() ? 0 : Nan::To<double>(info[2]).FromJust();
  self->m_collisionShape = std::make_shared<btBoxShape>(
    btVector3(btScalar(dx), btScalar(dy), btScalar(dz)));
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(mox::physics::RigidBody::isBox)
{
  GET_SELF(mox::physics::RigidBody, self);
  btCollisionShapePtr shptr =
    std::dynamic_pointer_cast<btBoxShape>(self->m_collisionShape);
  info.GetReturnValue().Set(Nan::New<v8::Boolean>(shptr.get() != nullptr));
}

v8::Local<v8::Object> mox::physics::RigidBody::NewInstance()
{
  Nan::EscapableHandleScope scope;

  const unsigned argc = 1;
  v8::Local<v8::Value> argv[1] = {Nan::New("xxx").ToLocalChecked()};
  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
  v8::Local<v8::Object> instance = cons->NewInstance(argc, argv);

  return scope.Escape(instance);
}
