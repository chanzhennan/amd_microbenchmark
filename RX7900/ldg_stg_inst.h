
#include "hip/hip_runtime.h"

__device__ __forceinline__  // ptr -> ret
    uint4
    ldg_cs(const void *ptr) {
  uint4 ret;
  asm volatile(
      "flat_load_b128 %0, %1;\n"
      "s_waitcnt lgkmcnt(0);"
      : "=v"(ret)
      : "v"(ptr));

  return ret;
}

__device__ __forceinline__  // reg -> ptr
    void
    stg_cs(uint4 &reg, void *ptr) {
  asm volatile(
      "flat_store_b128 %1, %0;\n"
      "s_waitcnt lgkmcnt(0);"
      : "=v"(reg)
      : "v"(ptr));
}
