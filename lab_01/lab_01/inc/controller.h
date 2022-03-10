#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "draw.h"
#include "model.h"
#include "errors.h"
#include "request.h"
#include "file_io.h"

int controller(scene_t scene, request_t &request);

#endif // CONTROLLER_H
