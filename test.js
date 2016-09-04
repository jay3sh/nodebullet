
let physics = require('./build/Debug/physics');

let world = new physics.World();

let box = new physics.RigidBody().initBox(10,10,10).setMass(2).translateTo(10,2,2);

console.log(world, box, box.isBox(), box.getMass());
