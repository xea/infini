#include "World.h"

Logger * World::logger = Logger::getLogger("World");

void World::initialize() {
	logger->info("Ez a masik thread");
}

bool World::start() {

	//thread newthread([]() { logger->info("Ez egy lambda"); });
	//newthread.join();	

	return false;
}

bool World::stop() {
	return false;
}

bool World::add(Entity& entity) {
	entities.push_back(&entity);

	logger->debug("Entity added");

	return true;
}