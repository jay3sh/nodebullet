
#ifndef NB_BULLET_H
#define NB_BULLET_H

#include <nan.h>
#include "node.h"

namespace nb {

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void init(Local<Object> exports);
}
#endif // NB_BULLET_H
