
#include "helper.h"
#include "pointers.h"
#include "btBulletDynamicsCommon.h"
#include "world.h"

Nan::Persistent<v8::Function> mox::physics::World::constructor;

mox::physics::World::World()
{
	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	btCollisionDispatcher* dispatcher = new	btCollisionDispatcher(collisionConfiguration);

	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;

	btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);

	dynamicsWorld->setGravity(btVector3(0,-9.8,0));

	//delete dynamics world
	delete dynamicsWorld;

	//delete solver
	delete solver;

	//delete broadphase
	delete overlappingPairCache;

	//delete dispatcher
	delete dispatcher;

	delete collisionConfiguration;
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
