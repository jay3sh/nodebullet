{
  "targets": [
    {
      "target_name": "bullet",
      "include_dirs" : [
          "<!(node -e \"require('nan')\")",
          "<(BULLET_PHYSICS_ROOT)/include/bullet",
          "inc"
      ],
      "libraries" : [
        "<(BULLET_PHYSICS_ROOT)/lib/BulletDynamics_Debug.lib",
        "<(BULLET_PHYSICS_ROOT)/lib/BulletCollision_Debug.lib",
        "<(BULLET_PHYSICS_ROOT)/lib/LinearMath_Debug.lib"
      ],
      "sources": [
        "src/bullet.cpp",
        "src/world.cpp"
      ]
    }
  ]
}
