#include "World.h"

Logger * World::logger = Logger::getLogger("World");

void World::initialize() {
	logger->info("Initializing World");
}

bool World::start() {
	
	worldThread = new thread([this]() { run(); });
	
	return false;
}

bool World::stop() {
	running = false;
	worldThread->join();

	return false;
}

bool World::add(Entity& entity) {
	entities.push_back(&entity);

	logger->debug("Entity added");

	return true;
}

std::list<Entity *> World::listEntities() {
	// FIXME return a copy of this list, not the original list itself
	return entities;
}

void World::attachScript(Script& script) {
	script.setScriptingInterface(*this);
	loadedScripts.push_back(&script);
}

void World::run() {
	logger->debug("Initializing world");

	for (Script *currentScript : loadedScripts) {
		currentScript->onStart();
	}

	running = true;

	while (running) {
		for (Script *currentScript : loadedScripts) {
			currentScript->onUpdate();
		}
	}

	
}
