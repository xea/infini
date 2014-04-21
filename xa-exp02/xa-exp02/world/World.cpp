#include "World.h"

Logger * World::logger = Logger::getLogger("World");

void World::initialize() {
	logger->info("Initializing World");
	activeScript = NULL;
}

bool World::start() {
	
	worldThread = new thread([](World& localWorld) { localWorld.run(); }, *this);
	
	return false;
}

bool World::stop() {
	
	worldThread->join();

	return false;
}

bool World::add(Entity& entity) {
	entities.push_back(&entity);

	logger->debug("Entity added");

	return true;
}

void World::attachScript(Script& script) {
	activeScript = &script;
	activeScript->setScriptingInterface(*this);
}

void World::run() {
	logger->debug("Initializing world");

	if (activeScript != NULL) {
		activeScript->onStart();
	}
}
