# Overworld Doors

Doors that take you from the overworld to an underworld (ie dungeon)

When the player collides with a door, take the player to the underworld,
positioned where the door says.

## how to encode/store the destination?

I don't want to add destination bytes to the entities array, as only doors will use them.

### idea: encode in the entity type
Make the door entity type be say 2, so 0x02;

then when storing a door in the entities array, store it as bIIII0010, where IIII is the id of the door.

Then use the id to find the door in the door array to get its destination.

Can also use door ids to save whether they are locked or not
