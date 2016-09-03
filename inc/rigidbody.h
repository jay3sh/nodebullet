#pragma once

#include <nan.h>

namespace mox {
  namespace physics {

    class RigidBody : public Nan::ObjectWrap {
    public:
      static void Init(v8::Local<v8::Object> namespc);

      static v8::Local<v8::Object> NewInstance();

    private:
      explicit RigidBody();
      ~RigidBody();

      static NAN_METHOD(New);


      static Nan::Persistent<v8::Function> constructor;
    };

  }
}
