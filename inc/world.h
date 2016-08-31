#pragma once

#include <nan.h>

namespace mox {
  namespace physics {

    class World : public Nan::ObjectWrap {
    public:
      static void Init(v8::Local<v8::Object> namespc);

    private:
      explicit World();
      ~World();

      static NAN_METHOD(New);
      
      static Nan::Persistent<v8::Function> constructor;
    };

  }
}

