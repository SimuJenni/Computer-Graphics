// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  float theta = degrees/180*pi;
  float x = axis[0];
  float y = axis[1];
  float z = axis[2];
  mat3 m = mat3(
		cos(theta)+(1-cos(theta))*x*x, (1-cos(theta))*x*y + sin(theta)*z, (1-cos(theta))*x*z-sin(theta)*y,
		(1-cos(theta))*x*y-sin(theta)*z, cos(theta)+(1-cos(theta))*y*y, (1-cos(theta))*y*z+sin(theta)*x,
		(1-cos(theta))*x*z+sin(theta)*y, (1-cos(theta))*y*z-sin(theta)*x, cos(theta)+(1-cos(theta))*z*z
		);
  return m;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  mat3 rot = rotate(degrees, up);
  eye = rot*eye;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  vec3 axis = glm::cross(eye, up);
  axis = glm::normalize(axis);
  mat3 rot = rotate(degrees, axis);
  eye = rot*eye;
  up = rot*up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  vec3 w = vec3(eye);
  w = glm::normalize(w);
  vec3 u = glm::cross(up, w);
  u = glm::normalize(u);
  vec3 v = glm::cross(w,u);
  float e_u = glm::dot(eye, u);
  float e_v = glm::dot(eye, v); 
  float e_w = glm::dot(eye, w); 
  mat4 m = mat4(
		u[0], u[1], u[2], -e_u,
		v[0], v[1], v[2], -e_v,
		w[0], w[1], w[2], -e_w,
		0, 0, 0, 1);
  m = glm::transpose(m);
  return m;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
