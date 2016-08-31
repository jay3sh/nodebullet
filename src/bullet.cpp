

#include "bullet.h"
#include "world.h"

void mox::physics::init(Local<Object> exports)
{
  mox::physics::World::Init(exports);
}

NODE_MODULE(mox, mox::physics::init)
