#include <gr/collision/gr_collision_data.h>

const char* grCollData::getJointNodeName(u32 nodeIndex) {
    if (nodeIndex >= m_vtxLen) {
        return 0;
    }
    return m_jointDatas[nodeIndex].m_name;
}
