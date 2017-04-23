#ifndef XA_VIEW_H
#define XA_VIEW_H

#include <memory>
#include <tuple>

#include <engine/Renderer.h>

enum class ViewResult : unsigned int {
	NoError,
	InitialisationFailed,
	WindowCreationError
};

class View {

public:
	virtual std::tuple<int, int> getResolution() = 0;

	virtual void setRenderer(std::unique_ptr<Renderer> renderer) = 0;

	virtual ViewResult start() = 0;

	virtual void stop() = 0;

	virtual bool shouldClose() = 0;

	virtual void swapBuffers() = 0;
};

#endif // XA_VIEW_H