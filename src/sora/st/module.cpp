#include "gm/gm_lib.h"
#include <st/module.h>

void moUnResolvedMessage(char const*) { }

static const u32 NumStages = 49;
static StageModuleId StageModuleIds[NumStages] = {
    { Stages::BattleFieldS, "st_battles.rel" },
    { Stages::BattleField, "st_battle.rel" },
    { Stages::Skyworld, "st_palutena.rel" },
    { Stages::YoshiIsland, "st_crayon.rel" },
    { Stages::DistantPlanet, "st_earth.rel" },
    { Stages::Smashville, "st_village.rel" },
    { Stages::FrigateOrpheon, "st_orpheon.rel" },
    { Stages::PokemonStadium2, "st_stadium.rel" },
    { Stages::ShadowMoses, "st_metalgear.rel" },
    { Stages::MarioCircuit, "st_kart.rel" },
    { Stages::DelfinoPlaza, "st_dolpic.rel" },
    { Stages::_75m, "st_donkey.rel" },
    { Stages::Norfair, "st_norfair.rel" },
    { Stages::Hanenbow, "st_plankton.rel" },
    { Stages::Summit, "st_ice.rel" },
    { Stages::WarioWare, "st_madein.rel" },
    { Stages::LylatCruise, "st_starfox.rel" },
    { Stages::MarioBros, "st_Famicom.rel" },
    { Stages::RumbleFalls, "st_Jungle.rel" },
    { Stages::MushroomyKingdom, "st_mariopast.rel" },
    { Stages::SpearPillar, "st_tengan.rel" },
    { Stages::LuigiMansion, "st_mansion.rel" },
    { Stages::PirateShip, "st_pirates.rel" },
    { Stages::FinalDestination, "st_final.rel" },
    { Stages::GreenHillZone, "st_greenhill.rel" },
    { Stages::PictoChat, "st_pictchat.rel" },
    { Stages::FlatZone2, "st_gw.rel" },
    { Stages::PortTown, "st_fzero.rel" },
    { Stages::CastleSiege, "st_emblem.rel" },
    { Stages::Halberd, "st_halberd.rel" },
    { Stages::Temple, "st_dxshrine.rel" },
    { Stages::YoshiIslandMelee, "st_dxyorster.rel" },
    { Stages::JungleJapes, "st_dxgarden.rel" },
    { Stages::Onett, "st_dxonett.rel" },
    { Stages::GreenGreens, "st_dxgreens.rel" },
    { Stages::RainbowCruise, "st_dxrcruise.rel" },
    { Stages::BigBlue, "st_dxbigblue.rel" },
    { Stages::Corneria, "st_dxcorneria.rel" },
    { Stages::PokemonStadium, "st_dxpstadium.rel" },
    { Stages::Brinstar, "st_dxzebes.rel" },
    { Stages::BridgeOfEldin, "st_oldin.rel" },
    { Stages::NewPorkCity, "st_newpork.rel" },
    { Stages::HomeRunContest, "st_homerun.rel" },
    { Stages::Builder, "st_stageedit.rel" },
    { Stages::OnlineTraining, "st_otrain.rel" },
    { Stages::RestArea, "st_heal.rel" },
    { Stages::TargetSmash, "st_tbreak.rel" },
    { Stages::CharacterRoll, "st_croll.rel" },
    { Stages::Config, "st_config.rel" },
};

namespace moModule {
    char const* getName(u32 i) {
        return StageModuleIds[i].name;
    }
}

char const* moGetStageModuleName(srStageKind kind) {
    char const* name = 0;
    for (u32 i = 0; i < NumStages; i++) {
        if (kind == StageModuleIds[i].kind) {
            name = moModule::getName(i);
            break;
        }
    }
    return name;
}
