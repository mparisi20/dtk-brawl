#include <memory.h>
#include <types.h>
#include <gr/gr_gimmick.h>
#include <gr/gr_yakumono.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>

#include <st_crayon/gr_crayon.h>

#if 0
mo_stage/st_crayon/gr_crayon_kumo.cpp:
	.text       base 80d6c6e0 start:0x80d6efe0 end:0x80d6f44c
	.rodata     base 80d77a48 start:0x80d77ab8 end:0x80d77ac4
	.data       base 80d77b84 start:0x80d78864 end:0x80d78a94

mo_stage/st_crayon/gr_crayon_kumo.cpp:
	.text       start:0x00002900 end:0x00002D6C
	.rodata     start:0x00000070 end:0x0000007C
	.data       start:0x00000CE0 end:0x00000F10

#endif


grCrayonKumo* grCrayonKumo::create(int mdlIndex, const char *taskName) {
    grCrayonKumo* kumo = new (Heaps::StageInstance) grCrayonKumo(mdlIndex, taskName);
    if (kumo) {
        kumo->setMdlIndex(mdlIndex);
    }
    return kumo;
}

grCrayonKumo::~grCrayonKumo() { }

u32 g_80d78864[8] = { 0, 1, 1, 2, 3, 4, 4, 5 };

inline void grCrayonKumo::updateRotate(Vec3f* rotate, float delta) {
    for (u32 r25 = 0; r25 < getModelCount(); r25++) {
        getRotate(rotate, m_sceneModels[r25], 1);
        rotate->m_y += delta;
        setRotate(rotate, m_sceneModels[r25], 1);
    }
}

// vtable 0x80d78a94
// TODO: Fix register and stack ordering for many local variables
void grCrayonKumo::update(float deltaFrame) {
// r27 this
// f30 deltaFrame
    nw4r::g3d::ScnMdl* scnMdl;
    gfModelAnimation* mdlAnim;
    u32 r28;
    nw4r::g3d::ResMdl resMdl;
    u32 nMdls; //r23
    u32 r25;
    u32 r26;
    int instanceSize;
    Vec3f rotate; // 0x28
    nw4r::g3d::ResAnmClr anmClr;
    nw4r::g3d::AnmObjTexPatRes* texPatRes;
    nw4r::g3d::AnmObjMatClrRes* matClrRes;
    nw4r::g3d::ResAnmTexPat anmTexPat;
    MEMAllocator* allocator;
    int instanceSize2;


    grCrayon::update(deltaFrame);
    switch (unk15C) {
        case 0:
        case 1:
        case 7:
            for (r25 = 0; r25 < getModelCount(); r25++) {
                //Vec3f rotate; // 0x28
                getRotate(&rotate, m_sceneModels[r25], 1);
                rotate.m_y += 3.0f;
                setRotate(&rotate, m_sceneModels[r25], 1);
            }
            //updateRotate(&rotate, 3.0f);
            break;
        case 3:
        case 4:
        case 5:
            for (r25 = 0; r25 < getModelCount(); r25++) {
                //Vec3f rotate; // 0x28
                getRotate(&rotate, m_sceneModels[r25], 1);
                rotate.m_y += 1.5f;
                setRotate(&rotate, m_sceneModels[r25], 1);
            }
            //updateRotate(&rotate, 1.5f);
            break;
        default:
            break;
    }
    if (0.0f == unk160) {
        switch (unk15C) {
            case 6:
            case 2:
                setVisibility(0);
                break;
            default:
                r28 = 0;
                nMdls = getModelCount();
                for ( ; r28 != nMdls; r28++) {
                    // r29 = r28*4
                    // 0x44 m_sceneModels
                    // r31 scnMdl
                    // r30 mdlAnim
                    // r24 resMdl
                    // r25 g_80d78864
                    scnMdl = m_sceneModels[r28];
                    if (!scnMdl) {
                        break;
                    }
                    mdlAnim = m_modelAnims[r28];
                    if (!mdlAnim) {
                        break;
                    }
                    resMdl = scnMdl->unkE8;
                    if (!resMdl.ptr()) {
                        break;
                    }
                    gfModelAnimation::unbind(scnMdl);
                    r26 = g_80d78864[unk15C];
                    if (r26 < mdlAnim->m_resFile.GetResAnmTexPatNumEntries()) {
                        anmTexPat =
                            mdlAnim->m_resFile.GetResAnmTexPat(r26);
                        if (anmTexPat.ptr()) {
                            allocator = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
                            // int instanceSize;
                            // nw4r::g3d::ResAnmTexPat texPat(anmTexPat);
                            // nw4r::g3d::ResMdl mdl(resMdl);
                            texPatRes = nw4r::g3d::AnmObjTexPatRes::Construct(allocator,
                                &instanceSize, anmTexPat, resMdl, false);
                            if (texPatRes) {
                                // nw4r::g3d::ResMdl resMdl2(resMdl);
                                texPatRes->Bind(resMdl);
                                if (mdlAnim->m_anmObjTexPatRes) {
                                    mdlAnim->m_anmObjTexPatRes->Destroy();
                                }
                                mdlAnim->m_anmObjTexPatRes = texPatRes;
                            }
                        }
                    }
                    r26 = g_80d78864[unk15C];
                    if (r26 < mdlAnim->m_resFile.GetResAnmClrNumEntries()) {
                        anmClr =
                            mdlAnim->m_resFile.GetResAnmClr(r26);
                        if (anmClr.ptr()) {
                            allocator = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
                            // int instanceSize;
                            // nw4r::g3d::ResAnmClr anmCl(anmClr);
                            // nw4r::g3d::ResMdl mdl(resMdl);
                            matClrRes = nw4r::g3d::AnmObjMatClrRes::Construct(allocator,
                                &instanceSize2, anmClr, resMdl, false);
                            if (matClrRes) {
                                // nw4r::g3d::ResMdl resMdl2(resMdl);
                                matClrRes->Bind(resMdl);
                                if (mdlAnim->m_anmObjMatClrRes) {
                                    mdlAnim->m_anmObjMatClrRes->Destroy();
                                }
                                mdlAnim->m_anmObjMatClrRes = matClrRes;
                            }
                        }
                    }
                    gfModelAnimation::bind(scnMdl, mdlAnim);
                    mdlAnim->setFrame(unk160);
                    mdlAnim->setUpdateRate(deltaFrame);
                }
                setVisibility(1);
                break;
        }
    } 
}

#if 0
stack:

1c
20
24

Vec3f
28
2c
30

static MEMAllocator* getMEMAllocator(Heaps::HeapType heapType);

static AnmObjTexPatRes* Construct(MEMAllocator* allocator, 
int* instanceSize, ResAnmTexPat anim, ResMdl mdl, bool hasCache);

static AnmObjMatClrRes* Construct(MEMAllocator* allocator,
int* size, ResAnmClr anim, ResMdl mdl, bool hasCache);

template<typename T, typename U>
void grCrayonKumo::helper(T anmClr, G3dObj*& obj) {
    if (anmClr.ptr()) {
        MEMAllocator* allocator = gfHeapManager::getMEMAllocator(Heaps::StageInstance);
        int instanceSize;
        U* matClrRes = U::Construct(allocator,
            &instanceSize, anmClr, resMdl, false);
        if (matClrRes) {
            matClrRes->Bind(resMdl);
            if (obj) {
                obj->Destroy();
            }
            obj = matClrRes;
        }
    }
}

#endif
