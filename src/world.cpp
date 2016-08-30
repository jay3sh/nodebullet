
#include "helper.h"
#include "world.h"

Nan::Persistent<v8::Function> nb::World::constructor;

nb::World::World()
{
}

nb::World::~World()
{
}

void nb::World::Init(v8::Local<v8::Object> namespc)
{
  DEFINE_FUNCTION_TEMPLATE("World", tpl);

  constructor.Reset(tpl->GetFunction());
  namespc->Set(Nan::New("World").ToLocalChecked(),
    tpl->GetFunction());

}

NAN_METHOD(nb::World::New)
{
  ALLOW_ONLY_CONSTRUCTOR(info);
  World *obj = new World();
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

/*
v8::Local<v8::Object> nb::World::NewInstance()
{
  Nan::EscapableHandleScope scope;

  const unsigned argc = 0;
  v8::Local<v8::Value> argv[] = {};
  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
  v8::Local<v8::Object> instance = cons->NewInstance(argc, argv);

  return scope.Escape(instance);
}
*/
