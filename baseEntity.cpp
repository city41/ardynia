#include "baseEntity.h"

bool BaseEntity::overlaps(BaseEntity* other) {
    return !(
        other->x                 >= x + width  ||
        other->x + other->width  <= x          ||
        other->y                 >= y + height ||
        other->y + other->height <= y
    );
}
