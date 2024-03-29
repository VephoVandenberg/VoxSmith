#pragma once

#include <stdint.h>

namespace VoxSmith
{
	enum class WindowEventType : uint8_t
	{
		KEYBOARD,
		MOUSE_MOVE,
		MOUSE_CLICK,
		WINDOW_RESIZE,
		CLOSE
	};

	struct WindowEvent
	{
		virtual inline WindowEventType getType() const = 0;
	};

	struct KeyboardEvent : public WindowEvent
	{
		int32_t m_key;
		int32_t m_action;

		inline WindowEventType getType() const override { return WindowEventType::KEYBOARD; }
	};

	struct MouseMoveEvent : public WindowEvent
	{
		int32_t x;
		int32_t y;

		inline WindowEventType getType() const override { return WindowEventType::MOUSE_MOVE; }
	};

	struct MouseClickEvent : public WindowEvent
	{
		int32_t m_action;
		int32_t m_button;

		inline WindowEventType getType() const override { return WindowEventType::MOUSE_CLICK; }
	};

	struct ResizeEvent : public WindowEvent
	{
		int32_t m_width;
		int32_t m_height;

		inline WindowEventType getType() const override { return WindowEventType::WINDOW_RESIZE; }
	};

	struct CloseEvent : public WindowEvent
	{
		inline WindowEventType getType() const override { return WindowEventType::CLOSE; }
	};
}
