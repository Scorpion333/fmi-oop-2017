#pragma once

class Knight {
	unsigned attack;
	unsigned defence;
	unsigned health;
	unsigned max_health;
	unsigned experience;
	unsigned successful_attacks;
public:
	Knight();
	Knight(const Knight& other);
	Knight& operator = (const Knight& other);

	unsigned real_attack();
	unsigned real_defence();
	unsigned real_max_health();

	void hit(Knight& other);
};