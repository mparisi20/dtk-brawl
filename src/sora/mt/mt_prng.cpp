#include <types.h>

////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

const char* OSGetAppGamename();
u32 OSGetStackPointer(void);
void OSReport(const char* msg, ...);

#ifdef __cplusplus
}
#endif

void srandi(s32 seed);
s32 randseed(void);
float randf(void);
float randaf(void);
s32 randi(s32 p1);

struct mtRand {
    virtual void init(s32 p1);
    virtual s32 generate();
    virtual float randf();
    virtual s32 getMax();
    virtual s32 randi();

    mtRand(s32 v) : seed(v) { }
    s32 seed;
};

struct mtPrngLog {
    u8 unk0[0x10];
    mtPrngLog(u32, u32);
};

struct mtPrngLogManager {
    u8 unk0[0xC];
    void addLog(mtPrngLog*);
};


/////////////////////////

#if 0
	.init		b=
	extab		b=
	extabindex	b=
	.text		b=8000c860, 8003fabc - 8003fd5c
	.ctors		b=804064e0, 80406510 - 80406514
	.dtors		b=
	.rodata		b=
	.data		b=80420680, 8042ae50 - 8042ae6c
	.bss		b=
	.sdata		b=
	.sbss		b=8059ff80, 805a00b8 - 805a00c0
	.sdata2		b=805a1320, 805a1748 - 805a176c
	.sbss2		b=
#endif

void mtRand::init(s32 p1) {
    this->seed = p1;
}

#define MULT_VAL 0x41C64E6D
#define ADD_VAL 0x3039

s32 mtRand::generate() {
    return this->seed = this->seed * MULT_VAL + ADD_VAL & 0x7fffffff;
}

s32 mtRand::randi() {
    return generate();
}

static mtRand g_mtRand(0);
extern mtPrngLogManager g_mtPrngLogManager;

// [0, 1] random float
float mtRand::randf() {
    return randi() / 2.147483647e9;
}

void srandi(s32 seed) {
    g_mtRand.seed = seed;
}

s32 randseed() {
    return g_mtRand.seed;
}

// Note: This function is meant to be deadstripped - it's only here
// to correct the order in which the compiler emits floating-point constants.
static float unused(u32 n) {
    return n;
}

// get random float
float randf() {
    mtRand* ptr = &g_mtRand;
    u32 val = ptr->generate();
    mtPrngLog log(val, OSGetStackPointer());
    g_mtPrngLogManager.addLog(&log);
    return (val >> 8) / 8388608.0f;
}

// get random float
float randaf() {
    mtRand* ptr = &g_mtRand;
    u32 val = ptr->generate();
    mtPrngLog log(val, OSGetStackPointer());
    g_mtPrngLogManager.addLog(&log);
    return 2.0f * ((val >> 8) / 8388608.0f - 0.5f);
}

// [0, 256*p1] random int
s32 randi(s32 p1) {
    mtRand* ptr = &g_mtRand;
    u32 val = ptr->generate();
    mtPrngLog log(val, OSGetStackPointer());
    g_mtPrngLogManager.addLog(&log);
    float scaled = ((val >> 8) / 8388608.0f);

    return p1 * scaled;
}

s32 mtRand::getMax() {
    return 0x7fffffff;
}
