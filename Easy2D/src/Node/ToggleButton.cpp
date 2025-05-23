#include <easy2d/e2dnode.h>

easy2d::ToggleButton::ToggleButton()
	: Button()
	, _toggle(true)
	, _normalOff(nullptr)
	, _mouseoverOff(nullptr)
	, _selectedOff(nullptr)
	, _disabledOff(nullptr)
{
}

easy2d::ToggleButton::ToggleButton(Node * toggleOnNormal, Node * toggleOffNormal, const Function<void()>& func)
	: Button()
	, _toggle(true)
	, _normalOff(nullptr)
	, _mouseoverOff(nullptr)
	, _selectedOff(nullptr)
	, _disabledOff(nullptr)
{
	this->setNormal(toggleOnNormal);
	this->setNormalOff(toggleOffNormal);
	this->setClickFunc(func);
}

easy2d::ToggleButton::ToggleButton(Node * toggleOnNormal, Node * toggleOffNormal, Node * toggleOnSelected, Node * toggleOffSelected, const Function<void()>& func)
	: Button()
	, _toggle(true)
	, _normalOff(nullptr)
	, _mouseoverOff(nullptr)
	, _selectedOff(nullptr)
	, _disabledOff(nullptr)
{
	this->setNormal(toggleOnNormal);
	this->setNormalOff(toggleOffNormal);
	this->setSelected(toggleOnSelected);
	this->setSelectedOff(toggleOffSelected);
	this->setClickFunc(func);
}

easy2d::ToggleButton::ToggleButton(Node * toggleOnNormal, Node * toggleOffNormal, Node * toggleOnMouseOver, Node * toggleOffMouseOver, Node * toggleOnSelected, Node * toggleOffSelected, const Function<void()>& func)
	: Button()
	, _toggle(true)
	, _normalOff(nullptr)
	, _mouseoverOff(nullptr)
	, _selectedOff(nullptr)
	, _disabledOff(nullptr)
{
	this->setNormal(toggleOnNormal);
	this->setNormalOff(toggleOffNormal);
	this->setMouseOver(toggleOnMouseOver);
	this->setMouseOverOff(toggleOffMouseOver);
	this->setSelected(toggleOnSelected);
	this->setSelectedOff(toggleOffSelected);
	this->setClickFunc(func);
}

easy2d::ToggleButton::ToggleButton(Node * toggleOnNormal, Node * toggleOffNormal, Node * toggleOnMouseOver, Node * toggleOffMouseOver, Node * toggleOnSelected, Node * toggleOffSelected, Node * toggleOnDisabled, Node * toggleOffDisabled, const Function<void()>& func)
	: Button()
	, _toggle(true)
	, _normalOff(nullptr)
	, _mouseoverOff(nullptr)
	, _selectedOff(nullptr)
	, _disabledOff(nullptr)
{
	this->setNormal(toggleOnNormal);
	this->setNormalOff(toggleOffNormal);
	this->setMouseOver(toggleOnMouseOver);
	this->setMouseOverOff(toggleOffMouseOver);
	this->setSelected(toggleOnSelected);
	this->setSelectedOff(toggleOffSelected);
	this->setDisabled(toggleOnDisabled);
	this->setDisabledOff(toggleOffDisabled);
	this->setClickFunc(func);
}

bool easy2d::ToggleButton::getState() const
{
	return _toggle;
}

void easy2d::ToggleButton::setState(bool bState)
{
	if (_toggle != bState)
	{
		_toggle = bState;
		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setNormal(Node * normal)
{
	if (normal != _normal)
	{
		// 移除旧的
		if (_normal)
		{
			this->removeChild(_normal);
		}
		// 添加新的
		if (normal)
		{
			this->addChild(normal);
			this->setSize(normal->getWidth(), normal->getHeight());
		}
		_normal = normal;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setMouseOver(Node * mouseover)
{
	if (mouseover != _mouseover)
	{
		// 移除旧的
		if (_mouseover)
		{
			this->removeChild(_mouseover);
		}
		// 添加新的
		if (mouseover)
		{
			this->addChild(mouseover);
		}
		_mouseover = mouseover;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setSelected(Node * selected)
{
	if (selected != _selected)
	{
		// 移除旧的
		if (_selected)
		{
			this->removeChild(_selected);
		}
		// 添加新的
		if (selected)
		{
			this->addChild(selected);
		}
		_selected = selected;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setDisabled(Node * disabled)
{
	if (disabled != _disabled)
	{
		// 移除旧的
		if (_disabled)
		{
			this->removeChild(_disabled);
		}
		// 添加新的
		if (disabled)
		{
			this->addChild(disabled);
		}
		_disabled = disabled;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setNormalOff(Node * normal)
{
	if (normal != _normalOff)
	{
		// 移除旧的
		if (_normalOff)
		{
			this->removeChild(_normalOff);
		}
		// 添加新的
		if (normal)
		{
			this->addChild(normal);
		}
		_normalOff = normal;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setMouseOverOff(Node * mouseover)
{
	if (mouseover != _mouseoverOff)
	{
		// 移除旧的
		if (_mouseoverOff)
		{
			this->removeChild(_mouseoverOff);
		}
		// 添加新的
		if (mouseover)
		{
			this->addChild(mouseover);
		}
		_mouseoverOff = mouseover;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setSelectedOff(Node * selected)
{
	if (selected != _selectedOff)
	{
		// 移除旧的
		if (_selectedOff)
		{
			this->removeChild(_selectedOff);
		}
		// 添加新的
		if (selected)
		{
			this->addChild(selected);
		}
		_selectedOff = selected;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::setDisabledOff(Node * disabled)
{
	if (disabled != _disabledOff)
	{
		// 移除旧的
		if (_disabledOff)
		{
			this->removeChild(_disabledOff);
		}
		// 添加新的
		if (disabled)
		{
			this->addChild(disabled);
		}
		_disabledOff = disabled;

		_updateState();
		_updateVisiable();
	}
}

void easy2d::ToggleButton::_updateState()
{
	if (_toggle)
	{
		_normal = _normal;
		_mouseover = _mouseover;
		_selected = _selected;
		_disabled = _disabled;

		if (_normalOff) _normalOff->setVisible(false);
		if (_mouseoverOff) _mouseoverOff->setVisible(false);
		if (_selectedOff) _selectedOff->setVisible(false);
		if (_disabledOff) _disabledOff->setVisible(false);
	}
	else
	{
		_normal = _normalOff;
		_mouseover = _mouseoverOff;
		_selected = _selectedOff;
		_disabled = _disabledOff;

		if (_normal) _normal->setVisible(false);
		if (_mouseover) _mouseover->setVisible(false);
		if (_selected) _selected->setVisible(false);
		if (_disabled) _disabled->setVisible(false);
	}
}

void easy2d::ToggleButton::_runCallback()
{
	_toggle = !_toggle;
	_updateState();

	if (_func)
	{
		_func();
	}
}
