/// \file GameDefines.h
/// \brief Game specific defines.

#pragma once
#define MY_PI 3.14159265358979323846f

#include "Defines.h"

/// \brief Sprite type.
///
/// Note: NUM_SPRITES must be last.
enum eSpriteType {
	SPIRE_BASE,
	SPIRE_PEAK,
	RANGE1,
	RANGE2,
	RANGE3,
	MAGE1,
	MAGE2,
	MAGE3,
	EXPLOSION,
	SMOKE,
	DESERTLEVEL,
	BASELEVEL,
	PLAINSLEVEL,
	// Hats
	VIKING_HAT,
	WIZARD_HAT,
	CYBORG_HAT,
	// Projectiles
	FIREBALL,
	BULLET1,
	THROWING_AXE,
	REDLINE,
	// Tilesets
	SIMPLE_TILE,
	DESERT_TILE,
	PLAINS_TILE,
	// Currency
	COIN,
	COIN_STACK,
	COIN_BAG,
	// GUI
	TITLE_SCREEN,
	MENU_BOX,
	BLACK_SQUARE,
	GREENLINE,
	// Characters
	HUMAN_IDLE,
	HUMAN_WALK,
	GOBLIN_WALK,
	GOBLIN_ATTACK,
	MINOTAUR_WALK,
	MINOTAUR_ATTACK,
	WOLF_WALK,
	WOLF_ATTACK,
	NUM_SPRITES //MUST BE LAST
}; //eSpriteType
