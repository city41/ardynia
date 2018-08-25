#ifndef entityTemplates_h
#define entityTemplates_h

#include "entityTypes.h"
#include "entity.h"
#include "bitmaps.h"
#include "blob.h"
#include "sword.h"

const Entity entityTemplates[] = {
    // 0, SWORD
    Entity(
        SWORD,
        16, // width
        16, // height
        DOWN,
        sword_tiles,
        sword_mask_tiles,
        0, // health
        1, // damage
        20, // duration (in frames),
        Sword::spawn,
        Sword::update,
        NULL, // render
        NULL // onCollide
    ),

    // 1, BLOB
    Entity(
        BLOB,
        16,
        16,
        DOWN,
        blob_tiles,
        blob_mask_tiles,
        2, // health
        1, // damage
        0, // duration
        NULL, // spawn
        NULL, // update, TODO: implement
        NULL, // render
        Blob::onCollide
    ),

    // 2, OVERWORLD_DOOR
    Entity(
        OVERWORLD_DOOR,
        16,
        16,
        DOWN,
        overworld_door_tiles,
        overworld_door_mask_tiles,
        0, // health
        0, // damage
        0, // duration
        NULL, // spawn
        NULL, // update, TODO: implement
        NULL, // render
        NULL  // onCollide
    )
};

#endif

