#pragma once

class ActionEvent {
public: 
	virtual bool IsAllowed() = 0;
	virtual void Invoke() = 0;
	virtual ~ActionEvent() = default;
};