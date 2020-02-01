#include "Response.h"

Response::Response(const Status &status) : status(status) {}

const Status &Response::getStatus() const {
    return status;
}
