// xa-exp05-test.cpp : Defines the entry point for the console application.
//

#include "actor/Actor.h"
#include "disruptor/Disruptor.h"
#include <memory>

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

TEST_CASE("Actor Paths", "[actorPath]") {
	std::shared_ptr<ActorPath> rootPath = std::make_shared<RootActorPath>();

	SECTION("A root actor path should have a name '/'") {
		REQUIRE(rootPath->getName() == "/");
		REQUIRE(rootPath->getFullName() == "/");
	}

	SECTION("A root actor path's parent is itself") {
		REQUIRE(rootPath->getParent() != nullptr);
		REQUIRE(rootPath->getParent() == rootPath);
		REQUIRE(rootPath->getParent()->getName() == "/");
		REQUIRE(rootPath->getParent()->getFullName() == "/");
		REQUIRE(rootPath->getParent()->getParent() != nullptr);
		REQUIRE(rootPath->getParent()->getParent()->getParent() != nullptr);
		REQUIRE(rootPath->getParent()->getParent()->getParent()->getFullName() == "/");
	}

	SECTION("A root actor path's root is itself") {
		REQUIRE(rootPath->getRoot() != nullptr);
		REQUIRE(rootPath->getRoot() == rootPath);
	}

	std::shared_ptr<ActorPath> childPath1 = std::make_shared<ChildActorPath>(rootPath, "child-1");
	std::shared_ptr<ActorPath> childPath2 = std::make_shared<ChildActorPath>(childPath1, "child-2");
	std::shared_ptr<ActorPath> childPath3 = std::make_shared<ChildActorPath>(childPath2, "child-3");

	SECTION("A child actor path has the name specified in the constructor") {
		REQUIRE(childPath1->getName() == "child-1");
		REQUIRE(childPath2->getName() == "child-2");
		REQUIRE(childPath3->getName() == "child-3");
	}

	SECTION("A child actor path's full name includes the parent's name") {
		REQUIRE(childPath1->getFullName() == "/child-1");
		REQUIRE(childPath2->getFullName() == "/child-1/child-2");
		REQUIRE(childPath3->getFullName() == "/child-1/child-2/child-3");
	}
}

TEST_CASE("", "") {

}

int main() {
	auto&& session = Catch::Session();
	int result = session.run(__argc, __argv);

	std::cout << "Press enter to exit." << std::endl;

	char c;
	std::cin.read(&c, 1);
    return 0;
}

