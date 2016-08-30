
#ifndef NB_WORLD_H
#define NB_WORLD_H

#include <nan.h>

namespace nb {

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

#endif // NB_WORLD_H
