
#include "helper.h"
#include "pointers.h"
#include "btBulletDynamicsCommon.h"
#include "world.h"

Nan::Persistent<v8::Function> mox::physics::World::constructor;

mox::physics::World::World()
{
  m_collisionConfiguration = std::make_shared<btDefaultCollisionConfiguration>();

  m_collisionDispatcher = std::make_shared<btCollisionDispatcher>(m_collisionConfiguration.get());

  m_dbvtBroadphase = std::make_shared<btDbvtBroadphase>();

  m_sequentialImpulseConstraintSolver =
    std::make_shared<btSequentialImpulseConstraintSolver>();

  m_discreteDynamicsWorld = std::make_shared<btDiscreteDynamicsWorld>(
    m_collisionDispatcher.get(),
    m_dbvtBroadphase.get(),
    m_sequentialImpulseConstraintSolver.get(),
    m_collisionConfiguration.get());

	m_discreteDynamicsWorld->setGravity(btVector3(0,-9.8,0));
}

mox::physics::World::~World()
{
}

void mox::physics::World::Init(v8::Local<v8::Object> namespc)
{
  DEFINE_FUNCTION_TEMPLATE("World", tpl);

  constructor.Reset(tpl->GetFunction());
  namespc->Set(Nan::New("World").ToLocalChecked(),
    tpl->GetFunction());
}

NAN_METHOD(mox::physics::World::New)
{
  ALLOW_ONLY_CONSTRUCTOR(info);
  World *obj = new World();
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

/*
v8::Local<v8::Object> mox::physics::World::NewInstance()
{
  Nan::EscapableHandleScope scope;

  const unsigned argc = 0;
  v8::Local<v8::Value> argv[] = {};
  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
  v8::Local<v8::Object> instance = cons->NewInstance(argc, argv);

  return scope.Escape(instance);
}
*/
