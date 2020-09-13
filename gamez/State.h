#pragma once

//to-do: create states so that we can use the gaameloop

namespace RealEngine {
	class State {
	public:
		virtual void Init() = 0; //pure virtual, gotta define these all in subclasses
		virtual void InputHandle() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() {} //{} or no?????
		virtual void Resume() {}
	};
}