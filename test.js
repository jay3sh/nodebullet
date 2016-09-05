
let physics = require('./build/Debug/physics');

let world = new physics.World();

let box = physics.RigidBody.make({
  type: physics.RigidBody.BOX,
  dimensions: [10, 20, 10],
  position: [100, 100, 0],
  mass : 5
});

world.addRigidBody(box);
