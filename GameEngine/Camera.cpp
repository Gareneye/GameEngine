#include "Camera.h"

const float Camera::PI = 3.14f;

Camera::Camera() : view(), speed(150.0f), distance(120.0f), radius(5.0f)
{
	view.setCenter(0, 0);

	view.setSize(
		std::stod(EngineResources::settings["res_x"]),
		std::stod(EngineResources::settings["res_y"])
		);
}


Camera::~Camera()
{
}

void Camera::update(float dt)
{
	sf::Vector2f posCamera = view.getCenter();

	float distanceX = posCamera.x - posTarget.x;
	float distanceY = posCamera.y - posTarget.y;

	if (abs(distanceX) < radius && abs(distanceY) < radius) return;

	float speedRatioX, speedRatioY;

	if (abs(distanceX) > distance)
		speedRatioX = distanceX / distance;
	else
		speedRatioX = sin( (distanceX / distance) * PI / 2);

	if (abs(distanceY) > distance)
		speedRatioY = distanceY / distance;
	else
		speedRatioY = sin((distanceY / distance) * PI / 2);

	view.setCenter(posCamera.x - speedRatioX * speed * dt, posCamera.y - speedRatioY * speed * dt);
}

void Camera::move(const sf::Vector2f & dest)
{
	posTarget = dest;
}

void Camera::drag(const sf::Vector2f & offset)
{
	posTarget = view.getCenter() + offset;
}

const sf::FloatRect & Camera::getViewport() const
{
	return view.getViewport();
}

const sf::View & Camera::getView() const
{
	return view;
}
