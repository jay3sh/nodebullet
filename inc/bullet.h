
#ifndef __NODE_BULLET_H__
#define __NODE_BULLET_H__

#include <nan.h>
#include "node.h"

namespace nodebullet {

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void init(Local<Object> exports);
}
#endif // __NODE_BULLET_H__
