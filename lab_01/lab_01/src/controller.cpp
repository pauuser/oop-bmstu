#include "../inc/controller.h"
#include <stdio.h>

error_t controller(scene_t scene, request_t &request)
{
    error_t rc = OK;

    static model_t model = init_model();

    int req_type = request.event;

    if (req_type == UPLOAD)
    {
        rc = input_model_from_file(model, request.filename);
    }
    else if (req_type == MOVE)
    {
        rc = move_model(model, request.data);
    }
    else if (req_type == SCALE)
    {
        rc = scale_model(model, request.data);
    }
    else if (req_type == ROTATE)
    {
        rc = rotate_model(model, request.data);
    }
    else if (req_type == SAVE)
    {
        rc = upload_model_to_file(request.filename, model);
    }
    else if (req_type == DRAW)
    {
        rc = draw_model(scene, model);
    }
    else
    {
        rc = UNKNOWN_COMMAND;
    }

    return rc;
}
