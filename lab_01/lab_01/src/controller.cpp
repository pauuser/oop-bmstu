#include "../inc/controller.h"

error_t controller(scene_t scene, request_t &request)
{
    error_t rc = OK;

    static model_t model = init_model();

    if (request.event == UPLOAD)
    {
        rc = input_model_from_file(model, request.filename);
    }
    else if (request.event == MOVE)
    {
        rc = move_model(model, request.data);
    }
    else if (request.event == SCALE)
    {
        rc = scale_model(model, request.data);
    }
    else if (request.event == ROTATE)
    {
        rc = rotate_model(model, request.data);
    }
    else if (request.event == SAVE)
    {
        rc = upload_model_to_file(request.filename, model);
    }
    else if (request.event == DRAW)
    {
        rc = draw_model(scene, model);
    }
    else
    {
        rc = UNKNOWN_COMMAND;
    }

    return rc;
}
