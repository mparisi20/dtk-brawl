#include <gf/gf_3d_scene_light_resource.h>
#include <gf/gf_3d_scene.h>
#include <types.h>

nw4r::g3d::LightObj* gfLightResHandle::getCharacterLight() {
    return g_gfSceneRoot->getLightObj(unk0);
}

void gfLightResHandle::setZoneLightSet(u8 p1) {
    g_gfSceneRoot->updateZoneLightSet(unk0, p1);
}
