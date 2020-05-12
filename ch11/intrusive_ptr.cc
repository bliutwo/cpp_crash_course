#include <boost/smart_ptr/intrusive_ptr.hpp>
#include "DeadMenOfDunharrow.h"

using IntrusivePtr = boost::intrusive_ptr<DeadMenOfDunharrow>;
size_t ref_count{};

void intrusive_ptr_add_ref(DeadMenOfDunharrow* d) {
    ref_count++;
}

void intrusive_ptr_release(DeadMenOfDunharrow* d) {
    ref_count--;
    if (ref_count == 0) delete d;
}
