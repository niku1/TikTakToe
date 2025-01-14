#include "window.h"
#include "scenes/menuscene.h"
#include <iostream>

Window::Window(std::string title)
    : window(sf::VideoMode(VWIDTH, VHEIGHT), title, sf::Style::Close,
             sf::ContextSettings(8, 0, 4, 3, 3))
{
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::Image icon;
    icon.loadFromFile("res/icon_small.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

Window::~Window() { window.close(); }

float Window::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (event.type == sf::Event::GainedFocus)
            focused = true;
        if (event.type == sf::Event::LostFocus)
            focused = false;
    }

    return clock.restart().asSeconds();
}

void Window::prepare() { window.clear(sf::Color(175, 175, 175, 255)); }

void Window::display() { window.display(); }

bool Window::isRunning() { return window.isOpen(); }

void Window::addEventHandler(EventHandler *handler)
{
    eventHandlers.push_back(handler);
}

sf::RenderWindow &Window::getWindow() { return window; }

bool Window::isFocused() const { return focused; }