#include "XEngine/Rendering/Camera.hpp"

namespace XEngine {

	Camera::Camera() { }

	/// <summary>
	/// Sets up camera.
	/// </summary>
	/// <param name="t_pos">Position of new camera.</param>
	Camera::Camera(glm::vec3 t_pos)
		: position(t_pos), world_up(glm::vec3(0.f, 1.f, 0.f)),
		yaw(-90.f), pitch(0.f), fov(45.f), forward(glm::vec3(0.f, 0.f, -1.f)),
		is_perspective(true), far_plane(100.f), near_plane(0.1f) {
		update_vectors();
	}

	/// <summary>
	/// Sets up camera.
	/// </summary>
	/// <param name="t_pos">Position of new camera.</param>
	/// <param name="t_yaw">Yaw.</param>
	/// <param name="t_pitch">Pitch.</param>
	Camera::Camera(glm::vec3 t_pos, float t_yaw, float t_pitch)
		: position(t_pos), world_up(glm::vec3(0.f, 1.f, 0.f)),
		yaw(t_yaw), pitch(t_pitch), fov(45.f), forward(glm::vec3(0.f, 0.f, -1.f)),
		is_perspective(true), far_plane(100.f), near_plane(0.1f) {
		update_vectors();
	}

	/// <summary>
	/// Updates camera vectors.
	/// </summary>
	void Camera::update_vectors() {
		//Get directions.
		glm::vec3 dir{};
		dir.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		dir.y = sin(glm::radians(pitch));
		dir.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		//Calculate directions.
		forward = glm::normalize(dir);
		right = glm::normalize(glm::cross(forward, world_up));
		up = glm::normalize(glm::cross(right, forward));
	}

	/// <summary>
	/// Temp. | For camera rotation.
	/// </summary>
	/// <param name="t_dx">X movement.</param>
	/// <param name="t_dy">Y movement.</param>
	void Camera::update_direction(double t_dx, double t_dy) {
		//Update yaw and pitch.
		yaw += t_dx;
		pitch += t_dy;
		//Limit pitch.
		if (pitch > 89.f) pitch = 89.f;
		else if (pitch < -89.f) pitch = -89.f;
		//Update vectors.
		update_vectors();
	}

	/// <summary>
	/// Calculate view matrix.
	/// </summary>
	/// <returns></returns>
	glm::mat4 Camera::get_view_matrix() {
		return glm::lookAt(position, position + forward, up);
	}

	/// <summary>
	/// Calculate projection matrix.
	/// </summary>
	/// <param name="t_clip_size"></param>
	/// <returns></returns>
	glm::mat4 Camera::get_projection_matrix(float t_clip_size) {
		if(is_perspective) return glm::perspective(glm::radians(fov), t_clip_size * aspect, near_plane, far_plane);
		else return glm::ortho(-t_clip_size, t_clip_size,
			-t_clip_size * aspect, t_clip_size * aspect, near_plane, far_plane);
	}

}