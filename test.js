
let physics = require('./build/Debug/physics');

let world = new physics.World();

//let box = new physics.RigidBody().initBox(10,10,10).setMass(2).translateTo(10,2,2);

//console.log(world, box, box.isBox(), box.getMass());


let box = physics.RigidBody.make({
  type: physics.RigidBody.BOX,
  dimensions: [10, 20, 10],
  position: [100, 100, 0],
  mass : 5
});

console.log(box);