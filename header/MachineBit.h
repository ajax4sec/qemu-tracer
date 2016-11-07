#define osBit32 1
#define isBusybox 1
#define isLubuntu32 0 
#define isLubuntu64 0
#if osBit32 
typedef uint32_t my_target_ulong;
#define kernelMinAddr 0xc0000000           //if an address less than kernelMinAddr, it is in user space, otherwise in kernel space 
#define gotMinAddr 0x80000000              //if the share object start address in 32 bit os
#define MY_TARGET_FMT_lx "%08x" 
#define MY_TARGET_lx "%x"
#else
typedef uint64_t my_target_ulong;
#define kernelMinAddr 0xf000000000000000
#define gotMinAddr 0x0000555555554000 
#define MY_TARGET_FMT_lx "%016lx" PRIx64
#define MY_TARGET_lx "%" PRIx64
#endif

#if isLubuntu32
//#define commOffset 0x3f0 //lubuntu32
//#define pidOffset 0x308 //lubuntu32
//#define realParentOffset 0x448
#endif

#if isLubuntu64
//#define commOffset 0x5e0 //lubuntu64
//#define pidOffset 0x438 //lubuntu64
//#define realParentOffset 0x448
#endif

#if isBusybox
#define commOffset 0x2d4 //busybox 
#define pidOffset 0x1f8 //busybox 
//#define tgidOffset 0x1fc //busybox 
#define realParentOffset 0x204 //busybox
#endif
