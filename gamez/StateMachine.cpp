#include "StateMachine.h"


namespace RealEngine {
	void StateMachine::PushState(StateRef newState, bool isReplacing) {
		this->adding = true;
		this->replacing = isReplacing;
		this->newState = std::move(newState);
	 }

	void StateMachine::PopState() {
		this->removing = true;
	}
	void StateMachine::ProcessStateChanges() {
		if (this->removing && !this->states.empty()) { //we only pop if the stack is occupied
			this->states.pop();

			if (!this->states.empty()) {
				this->states.top()->Resume();
			}

			this->removing = false;

		}

		if (this->adding) {
				//first check if there are already states on the stack, if there are, replace, if not, push onto empty stack
			if (!this->states.empty()) {
				if (this->replacing) {
					this->states.pop();
				}
				else {
					this->states.top()->Pause(); //if a state is not being replaced on the stack, then we pause the top of the stack before pushing
				}
			}
			this->states.push(std::move(this->newState)); //move transfers resources of the smart pointer
			this->states.top()->Init(); //initializing state, loading textures, etc
			this->adding = false;
		}

	}
	StateRef& StateMachine::GetActiveState() {
		return this->states.top();
	}
}