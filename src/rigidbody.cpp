
#include "helper.h"
#include "pointers.h"
#include "btBulletDynamicsCommon.h"
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
  constructor.Reset(tpl->GetFunction());
  namespc->Set(Nan::New("RigidBody").ToLocalChecked(),
    tpl->GetFunction());
}

NAN_METHOD(mox::physics::RigidBody::New)
{
  ALLOW_ONLY_CONSTRUCTOR(info);
  RigidBody *obj = new RigidBody();
  obj->Wrap(info.This());
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
