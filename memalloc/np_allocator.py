import ctypes
import numpy_allocator
import time
import os
sima_alloc = ctypes.CDLL(f"{os.getcwd()}/memalloc.so", mode=ctypes.RTLD_GLOBAL)
class _allocator(metaclass = numpy_allocator.type):
    _calloc_ = ctypes.addressof(sima_alloc._calloc)
    _free_ = ctypes.addressof(sima_alloc._free)
    _malloc_ = ctypes.addressof(sima_alloc._malloc)
    _realloc_ = ctypes.addressof(sima_alloc._realloc)

_allocator.__enter__()


if __name__ == "__main__":
    import numpy as np
    z = [None] * 2
    for k in range(len(z)):
        z[k] = np.ones([720, 1280, 3])
    for k in range(len(z)):
        print(z[k].shape)

    