
#include "helper.h"
#include "btBulletDynamicsCommon.h"
#include "pointers.h"
#include "rigidbody.h"

Nan::Persistent<v8::Function> mox::physics::RigidBody::constructor;

mox::physics::RigidBody::RigidBody()
{
  m_transform.setIdentity();
  m_mass = 0;
}

mox::physics::RigidBody::~RigidBody()
{

}

void mox::physics::RigidBody::Init(v8::Local<v8::Object> namespc)
{
  DEFINE_FUNCTION_TEMPLATE("RigidBody", tpl);

  Nan::SetMethod(tpl, "make", make);

  tpl->Set(Nan::New("BOX").ToLocalChecked(), Nan::New(1));
  tpl->Set(Nan::New("CYLINDER").ToLocalChecked(), Nan::New(2));
  tpl->Set(Nan::New("SPHERE").ToLocalChecked(), Nan::New(3));

  Nan::SetPrototypeMethod(tpl, "initBox", initBox);
  Nan::SetPrototypeMethod(tpl, "isBox", isBox);

  Nan::SetPrototypeMethod(tpl, "setMass", setMass);
  Nan::SetPrototypeMethod(tpl, "getMass", getMass);
  Nan::SetPrototypeMethod(tpl, "translateTo", translateTo);

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

NAN_METHOD(mox::physics::RigidBody::make)
{
  CHECK_NUM_ARGUMENTS(info, 1);

  v8::Local<v8::Object> def = Nan::To<v8::Object>(info[0]).ToLocalChecked();

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

NAN_METHOD(mox::physics::RigidBody::setMass)
{
  GET_SELF(mox::physics::RigidBody, self);
  CHECK_NUM_ARGUMENTS(info, 1);
  self->m_mass = info[0]->IsUndefined() ? 0 : Nan::To<double>(info[0]).FromJust();
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(mox::physics::RigidBody::getMass)
{
  GET_SELF(mox::physics::RigidBody, self);
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->m_mass));
}

NAN_METHOD(mox::physics::RigidBody::translateTo)
{
  GET_SELF(mox::physics::RigidBody, self);
  CHECK_NUM_ARGUMENTS(info, 3);
  double x = info[0]->IsUndefined() ? 0 : Nan::To<double>(info[0]).FromJust();
  double y = info[1]->IsUndefined() ? 0 : Nan::To<double>(info[1]).FromJust();
  double z = info[2]->IsUndefined() ? 0 : Nan::To<double>(info[2]).FromJust();
  self->m_transform.setOrigin(btVector3(x, y, z));
  info.GetReturnValue().Set(info.This());
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
