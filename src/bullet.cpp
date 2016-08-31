

#include "bullet.h"
#include "world.h"

void nb::init(Local<Object> exports)
{
  //exports->Set(Nan::New("World").ToLocalChecked(), tess);
  nb::World::Init(exports);
}

NODE_MODULE(nodebullet, nb::init)
