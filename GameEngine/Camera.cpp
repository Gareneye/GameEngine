#include "Camera.h"

const float Camera::PI = 3.14f;

Camera::Camera() : view(), maxSpeed(10.0f)
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

void Camera::update(float)
{
	sf::Vector2f posCamera = view.getCenter();

	if (posCamera == posTarget) return;

	float distanseRatioX = posCamera.x / posTarget.x;
	float distanseRatioY = posCamera.y / posTarget.y;

	float speedRatioX = cos(distanseRatioX * PI / 2);
	float speedRatioY = cos(distanseRatioY * PI / 2);

	view.setCenter(posCamera.x + speedRatioX * maxSpeed, posCamera.y + speedRatioY * maxSpeed);
}

void Camera::move(sf::Vector2f dest)
{
	posTarget = dest;
}

sf::FloatRect Camera::getViewport()
{
	return view.getViewport();
}

const sf::View & Camera::getView()
{
	return view;
}
