#pragma once

class ActionEvent {
public: 
	virtual void Invoke() = 0;
	virtual ~ActionEvent() = default;
};