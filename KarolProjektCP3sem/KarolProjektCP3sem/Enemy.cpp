#include "Enemy.h"
#include "Army.h"
#include "Archer.h"
#include "Matchlock.h"
#include "Pike.h"
#include "Sword.h"
#include "Cavalry.h"
#include "iostream"


Enemy::Enemy(const Map &_map)
{
    map = &_map;
    army = new Army(map->get_enemy_city());
    army->create_enemy_army_template();
    city = new City(map->get_enemy_city(), *army);
    print_army();
}

Enemy::Enemy()
{
}
