#pragma once

#include <memory>
#include <stack>
#include "State.h"


//goal is to have menu as a state? well see
namespace RealEngine {
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {
	public:
		StateMachine() {}
		~StateMachine() {}

		void PushState(StateRef newState, bool isReplacing = true); //wanna move on to next state, pop old, push new
		void PopState();

		void ProcessStateChanges(); // might not use this time????

		StateRef& GetActiveState();

	private:
		std::stack <StateRef> states;
		StateRef newState;

		bool removing;
		bool adding;
		bool replacing;

	};
}