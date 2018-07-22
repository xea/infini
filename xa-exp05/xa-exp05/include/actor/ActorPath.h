#pragma once

#ifndef XA_ACTOR_PATH_H
#define XA_ACTOR_PATH_H

#include <memory>
#include <string>

// This delimiter is used to separate path nodes in an actor path's string representation, eg. /user/test/sub-actor
static const std::string ACTOR_PATH_DELIMITER = "/";

// An actor path is a unique point in the hierarchy of actors in an actor system. It always links the leaf node in the path
// to it's root, ie. partial paths are not valid and are normally impossible to make. 
//
// An actor path does not point to a specific actor though, it's more like a symbolic link to a file on the file system. If 
// the pointed actor dies or gets replaced otherwise, the actor path itself will be still valid and unaware of this.
class ActorPath : public std::enable_shared_from_this<ActorPath> {
private:
	const std::string name;
protected:
	ActorPath(std::string name) : name(name) {};
public:
	const std::string& getName();
	virtual const std::string getFullName() = 0;
	virtual std::shared_ptr<ActorPath> getParent() = 0;
	virtual std::shared_ptr<ActorPath> getRoot() = 0;
};

// RootActorPath serves as an achor in a particular actor path hierarchy. Lookup queries that would otherwise
// propagate to path parents will just return references to this instance.
class RootActorPath : public ActorPath {
private:
public:
	// this should at some point take an Address too, to identify the physical path of the actor
	RootActorPath() : ActorPath(ACTOR_PATH_DELIMITER) {};
	const std::string getFullName() override;
	std::shared_ptr<ActorPath> getParent() override;
	std::shared_ptr<ActorPath> getRoot() override;
};

// Child actor paths are meant to be used by non-root (ie. every ordinary) actor reference.
class ChildActorPath : public ActorPath {
private:
	std::shared_ptr<ActorPath> parent;
public:
	ChildActorPath(std::shared_ptr<ActorPath> parent, const std::string name) : parent(parent), ActorPath(name) {};
	const std::string getFullName() override;
	std::shared_ptr<ActorPath> getParent() override;
	std::shared_ptr<ActorPath> getRoot() override;
};



#endif // XA_ACTOR_PATH_H