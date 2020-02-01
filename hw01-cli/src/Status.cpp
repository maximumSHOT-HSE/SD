
#include <Status.h>

bool Status::isSuccess() const {
    return statusCode == 0;
}
