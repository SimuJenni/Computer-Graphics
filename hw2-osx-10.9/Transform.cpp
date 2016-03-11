// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be
// COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.
mat3 Transform::rotate(const float degrees, const vec3 &axis) {
  // YOUR CODE FOR HW2 HERE
  // Please implement this.  Likely the same as in HW 1.
  float theta = degrees / 180 * pi;
  float x = axis[0];
  float y = axis[1];
  float z = axis[2];
  mat3 m = mat3(cos(theta) + (1 - cos(theta)) * x * x,
                (1 - cos(theta)) * x * y + sin(theta) * z,
                (1 - cos(theta)) * x * z - sin(theta) * y,
                (1 - cos(theta)) * x * y - sin(theta) * z,
                cos(theta) + (1 - cos(theta)) * y * y,
                (1 - cos(theta)) * y * z + sin(theta) * x,
                (1 - cos(theta)) * x * z + sin(theta) * y,
                (1 - cos(theta)) * y * z - sin(theta) * x,
                cos(theta) + (1 - cos(theta)) * z * z);
  return m;
}

void Transform::left(float degrees, vec3 &eye, vec3 &up) {
  // YOUR CODE FOR HW2 HERE
  // Likely the same as in HW 1.
  mat3 rot = rotate(degrees, up);
  eye = rot * eye;
}

void Transform::up(float degrees, vec3 &eye, vec3 &up) {
  // YOUR CODE FOR HW2 HERE
  // Likely the same as in HW 1.
  vec3 axis = glm::cross(eye, up);
  axis = glm::normalize(axis);
  mat3 rot = rotate(degrees, axis);
  eye = rot * eye;
  up = rot * up;
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) {
  // YOUR CODE FOR HW2 HERE
  // Likely the same as in HW 1.
  vec3 w = vec3(eye);
  w = glm::normalize(w);
  vec3 u = glm::cross(up, w);
  u = glm::normalize(u);
  vec3 v = glm::cross(w, u);
  float e_u = glm::dot(eye, u);
  float e_v = glm::dot(eye, v);
  float e_w = glm::dot(eye, w);
  mat4 m = mat4(u[0], u[1], u[2], -e_u, v[0], v[1], v[2], -e_v, w[0], w[1],
                w[2], -e_w, 0, 0, 0, 1);
  m = glm::transpose(m);
  return m;
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar) {
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // New, to implement the perspective transform as well.
  return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) {
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement scaling
  return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) {
  mat4 ret;
  // YOUR CODE FOR HW2 HERE
  // Implement translation
  return ret;
}

// To normalize the up direction and construct a coordinate frame.
// As discussed in the lecture.  May be relevant to create a properly
// orthogonal and normalized up.
// This function is provided as a helper, in case you want to use it.
// Using this function (in readfile.cpp or display.cpp) is optional.

vec3 Transform::upvector(const vec3 &up, const vec3 &zvec) {
  vec3 x = glm::cross(up, zvec);
  vec3 y = glm::cross(zvec, x);
  vec3 ret = glm::normalize(y);
  return ret;
}

Transform::Transform() {}

Transform::~Transform() {}
