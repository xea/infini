#ifndef XA_CONTEXT_STACK
#define XA_CONTEXT_STACK

#include <stack>

thread_local static std::stack<std::shared_ptr<ActorContext>> contextStack;

#endif // XA_CONTEXT_STACK
