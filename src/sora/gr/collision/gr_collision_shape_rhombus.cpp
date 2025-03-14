#include "mt/mt_vector.h"
#include <gr/collision/gr_collision_shape_rhombus.h>
#include <types.h>

#if 0

.text 80132b64 - 801330b8
.data 8045da88 - 8045daf0
.sdata2 805a2a24 - 805a2a2c

class clAABBox2D {
public:
    float m_unk1;
    float m_unk2;
    float m_unk3;
    float m_unk4;
};
class clRhombus2D {
public:
    Vec2f m_centerPos;
    Vec2f m_upPos;
    Vec2f m_downPos;
    Vec2f m_leftPos;
    Vec2f m_rightPos;
    clAABBox2D m_aabBox;
};
#endif


void grCollShapeRhombus::init() {
    m_rhombus.m_centerPos.clear();
    m_rhombus.m_upPos.clear();
    m_rhombus.m_downPos.clear();
    m_rhombus.m_leftPos.clear();
    m_rhombus.m_rightPos.clear();
    m_rhombus.m_aabBox.clear();
}

void grCollShapeRhombus::set(grCollShape& src) {
    *this = static_cast<grCollShapeRhombus&>(src);
}

void grCollShapeRhombus::move(Vec2f& displacement) {
    m_rhombus.move(displacement);
}

Vec2f subtract(Vec2f a, Vec2f b) {
    Vec2f diff = a - b;
    return diff;
}

Pos2D subtract(Pos2D a, Pos2D b) {
    Pos2D diff = a - b;
    return diff;
}

Pos2D copy(Pos2D a, Pos2D b) {
    a = b;
    return a;
}

Pos2D swap(Pos2D a, Pos2D b) {
    Pos2D c;
    c = a;
    a = b;
    b = c;
    return a;
}

Vec2f copy(Vec2f a, Vec2f b) {
    a = b;
    return a;
}

Vec2f swap(Vec2f a, Vec2f b) {
    Vec2f c;
    c = a;
    a = b;
    b = c;
    return a;
}


// TODO: there may be some inline helper function that is used for
// setDownPos, setLeftPos, etc, since they all exhibit the extra lwz/stw copies
inline void setPos(grCollShapeRhombus* ths, Vec2f base, Vec2f pos) {
    pos.addY(0.01f);
    ths->m_rhombus.move(base - pos);
}

// Moves the rhombus to the position specified in downPos by computing
// its displacement from the initial m_downPos. Also adjusts Y by +0.01f
void grCollShapeRhombus::setDownPos(Vec2f& downPos) {
    ;
    ;
    // Vec2f stack08, stack10, stack18, stack20;
    // stack20.m_x = downPos->m_x;
    // stack20.m_y = 0.01f + downPos->m_y;
    // stack08.m_x = stack20.m_x - m_rhombus.m_downPos.m_x;
    // stack08.m_y = stack20.m_y - m_rhombus.m_downPos.m_y;
    // stack08 -= m_rhombus.m_downPos;
    // stack10 = stack08;
    // stack18 = stack08;
    // Vec2f stack08(downPos->m_x - m_rhombus.m_downPos.m_x, 0.01f + downPos->m_y - m_rhombus.m_downPos.m_y);
    // Vec2f stack10 = stack08;
    // Vec2f stack18 = stack08;
    // Vec2f stack20(downPos->m_x, 0.01f + downPos->m_y);
    // m_rhombus.move(stack18);

    // Vec2f stack08 = { downPos->m_x - m_rhombus.m_downPos.m_x, 0.01f + downPos->m_y - m_rhombus.m_downPos.m_y };
    // Vec2f stack10 = stack08;
    // Vec2f stack18 = stack08;
    // Vec2f stack20 = { downPos->m_x, 0.01f + downPos->m_y };
    // Vec2f disp = { downPos->m_x, downPos->m_y + 0.01f };
    // m_rhombus.move(disp -  m_rhombus.m_downPos);

    // Vec2f disp(*downPos);
    // disp.addY(+ 0.01f);

    // m_rhombus.move( disp - m_rhombus.m_downPos);

    Pos2D local18;
    Pos2D local10(downPos.m_x, 0.01f + downPos.m_y);
    // float local10;
    // float localC;

    // local10.m_y = 0.01f + downPos->m_y;
    // local10.m_x = downPos->m_x;
    // local18.m_x = local10 - m_rhombus.m_downPos.m_x;
    // local18.m_y = localC - m_rhombus.m_downPos.m_y;

    //ec2f diff = subtract(local10, m_rhombus.m_downPos);
    m_rhombus.move(subtract(local10, Pos2D(m_rhombus.m_downPos.m_x, m_rhombus.m_downPos.m_y)).xy);

    // local10 -= m_rhombus.m_downPos;
    // m_rhombus.move(local10);

    //setPos(this, *downPos, m_rhombus.m_downPos);
}

