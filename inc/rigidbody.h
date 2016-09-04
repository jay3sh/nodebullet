#pragma once

#include <nan.h>
#include "pointers.h"

namespace mox {
  namespace physics {

    class RigidBody : public Nan::ObjectWrap {
    public:
      static void Init(v8::Local<v8::Object> namespc);

      static v8::Local<v8::Object> NewInstance();

      btCollisionShapePtr m_collisionShape;
      btTransform m_transform;
      btDefaultMotionStatePtr m_motionState;
      btRigidBodyPtr m_rigidBody;
      double m_mass;

    private:
      explicit RigidBody();
      ~RigidBody();

      static NAN_METHOD(New);

      static NAN_METHOD(make);

      static NAN_METHOD(initBox);
      static NAN_METHOD(isBox);

      //static NAN_METHOD(initCylinder);
      //static NAN_METHOD(initSphere);

      static NAN_METHOD(setMass);
      static NAN_METHOD(getMass);
      static NAN_METHOD(translateTo);

      static Nan::Persistent<v8::Function> constructor;
    };

  }
}
