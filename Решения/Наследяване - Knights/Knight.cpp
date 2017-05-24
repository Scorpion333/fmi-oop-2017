#include"Knight.h"

Knight::Knight()
	: attack(20), defence(10), health(150),
	max_health(150), experience(0), successful_attacks(0) {}

Knight::Knight(const Knight& other) {
	attack = other.attack;
	defence = other.defence;
	health = other.health;
	max_health = other.max_health;
	experience = other.experience;
	successful_attacks = other.successful_attacks;
}

Knight& Knight::operator =(const Knight& other) {
	attack = other.attack;
	defence = other.defence; 
	health = other.health;
	max_health = other.max_health;
	experience = other.experience;
	successful_attacks = other.successful_attacks;
	return *this;
}

unsigned Knight::real_attack() {
	return attack + 2 * experience;
}
unsigned Knight::real_defence() {
	return defence + experience;
}
unsigned Knight::real_max_health() {
	return max_health + experience;
}

void Knight::hit(Knight& other) {
	unsigned hit_attack = this->real_attack();
	unsigned hit_defence = other.real_defence();

	if (hit_attack > hit_defence) {
		other.health -= (hit_attack - hit_defence);
		successful_attacks++;
		if (successful_attacks % 20 == 0) {
			this->experience++;
		}
	}
}