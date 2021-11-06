#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Exports.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Vector2.h"
#include "Vector3.h"

class FLK_API Transform {
private:
	Vector3 position;
	Vector3 rotation;
	Vector3 localScale;

	Vector3 right;
	Vector3 up;
	Vector3 foward;

	glm::mat4 transform;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

public:
	Transform();
	~Transform();

	void SetPosition(float x, float y, float z);
	void SetPosition(Vector2 position);
	void SetPosition(Vector3 position);

	void SetRotation(float angle, Vector3 axis);
	void SetEulerAngles(Vector3 eulerAngles);	
	void RotateXAxis(float angle);
	void RotateYAxis(float angle);
	void RotateZAxis(float angle);

	void SetScale(float scale);
	void SetScale(Vector3 scale);

	void Translate(Vector3 position);
	
	void LookAt(Vector3 target);
	void LookAt(Vector3 target, Vector3 upVector);
	void LookAt(Vector3 position, Vector3 target, Vector3 upVector);
	
	glm::mat4 GetTransform() const;

	Vector3 GetFoward() const;
	Vector3 GetRight() const;
	Vector3 GetUp() const;
	Vector3 GetPosition() const;
	Vector3 GetRotation() const;
	Vector3 GetScale() const;
	
	void operator *=(const Transform& otherTransform);
	Transform operator *(const Transform& otherTransform) const;
	Vector3 operator *(const Vector3& otherVector) const;

private:

	void UpdateUnitVectors();
	void UpdateTransform();
};

#endif