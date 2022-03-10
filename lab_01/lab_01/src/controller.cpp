#include "../inc/controller.h"
#include <stdio.h>

int controller(scene_t scene, request_t &request)
{
    int rc = OK;

    static model_t model = init_model();

    int req_type = request.event;
    fprintf(stdout, "%d\n", req_type);

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

    return rc;
}
