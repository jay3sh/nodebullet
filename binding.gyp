{
  "targets": [
    {
      "target_name": "bullet",
      "include_dirs" : [
          "<!(node -e \"require('nan')\")",
          "<(BULLET_PHYSICS_ROOT)/include/bullet",
          "inc"
      ],
      "sources": [ "src/bullet.cpp" ]
    }
  ]
}
