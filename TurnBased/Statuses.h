#pragma once
#include "Entity.h"
//
//Bleed // damaging
//Poison // damaging
//Healing // negative damaging
//LowerAttack // lower stat
//LowerMana // lower stat
//LowerHealth // lower stat

void HealingStatuses(Entity* Person);
void DamageByStatus(Entity* Person);