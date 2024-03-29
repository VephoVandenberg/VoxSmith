#pragma once

#include <memory>

#include "../Core.hpp"
#include "../Window/Window.hpp"
#include "../Renderer/Renderer.hpp"

namespace VoxSmith
{
	struct WindowEvent;
	class UICanvasIMGUI;

	class VOX_SMITH_API Application
	{
	public:
		Application();
		virtual ~Application() noexcept;

		// these functions are derived in Sandbox where the client code is allowed
		virtual void update(float dt);
		virtual void draw();

		void run();
		void handleEvents(WindowEvent& e);

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

	private:
		std::unique_ptr<Window> m_window = nullptr;
		UICanvasIMGUI* m_UICanvas = nullptr;

		bool m_isRunning = false;
	};

	Application* createApplication();
}
