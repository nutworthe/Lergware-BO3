#include "includes.h"
struct ImVec3 {
    float x, y, z;
};

struct trace_s
{
public:
    ImVec3 normal;
private:
    byte _0xC[0x4];
public:
    std::float_t fraction;
    std::int32_t surfaceFlags;
private:
    byte _0x18[0xC];
public:
    std::int32_t hitType;
    std::int16_t hitId;
private:
    byte _0x2A[0xC];
public:
    std::uint16_t partGroup;
    bool allSolid;
    bool startSolid;
private:
    byte _0x3A[0x16];
public:
    std::int32_t hitPartition;
};

struct bullet_trace_results_s
{
public:
    trace_s trace;
public:
    ImVec3 hitPos;
    bool ignoreHitEnt;
private:
    byte _0x61[0x3];
public:
    std::int32_t surfaceType;
private:
    byte _0x68[0x8];
};

struct bullet_fire_params_s
{
public:
    std::int32_t weaponEntIndex;
    std::int32_t ignoreEntIndex;
    std::float_t damageMultiplier;
    std::int32_t methodOfDeath;
    ImVec3 origStart;
    ImVec3 start;
    ImVec3 end;
    ImVec3 dir;
private:
    byte _0x40[0xC];
};
struct bullet_hit_info_s
{
public:
    bullet_fire_params_s bp;
private:
    byte _0x76[0x4];
public:
    bullet_trace_results_s br;
    bullet_fire_params_s revBp;
private:
    byte _0x10C[0x4];
public:
    bullet_trace_results_s revBr;
    byte traceHit;
    byte revTraceHit;
    byte allSolid;
    byte voidFilled;
    std::int32_t sflags;
    std::int32_t sflagsRv;
    std::float_t damage;
private:
    byte _0x190[0x4];
public:
    std::float_t range;
private:
    byte _0x198[0x8];
};

struct bullet_penetration_info_s
{
public:
    bullet_hit_info_s hits[5];
    std::int32_t count;
private:
    byte _0x824[0xC];
};

