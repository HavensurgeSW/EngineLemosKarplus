#include "Transform.h"

#include "Utils.h"

Transform::Transform()
{
	position = Vector3::Zero();
	rotation = Vector3::Zero();
	localScale = Vector3::One();

	right = Vector3::Right();
	up = Vector3::Up();
	foward = Vector3::Foward();
	
	transform = glm::mat4(1.0f);
	translationMatrix = glm::mat4(1.0f);
	rotationMatrix = glm::mat4(1.0f);
	scaleMatrix = glm::mat4(1.0f);

	UpdateTransform();
	UpdateUnitVectors();
}

Transform::~Transform()
{

}

void Transform::SetPosition(float x, float y, float z)
{
	this->position = {x,y,z};
	translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));

	UpdateTransform();
}

void Transform::SetPosition(Vector2 position)
{
	SetPosition(position.x, position.y, 0.0f);
}

void Transform::SetPosition(Vector3 position)
{
	SetPosition(position.x, position.y, position.z);
}


void Transform::SetRotation(float angle, Vector3 axis)
{
	rotation = axis * angle;

	//rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(axis.x, axis.y, axis.z));
	//rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis.x, axis.y, axis.z));
	rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis.x, axis.y, axis.z));

	UpdateUnitVectors();
	UpdateTransform();
}

void Transform::SetEulerAngles(Vector3 eulerAngles)
{
	rotation.x = eulerAngles.x;
	rotation.y = eulerAngles.y;
	rotation.z = eulerAngles.z;

	rotationMatrix = glm::rotate(glm::mat4(1.0f), Utils::DegreesToRadians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
	rotationMatrix = glm::rotate(rotationMatrix, Utils::DegreesToRadians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
	rotationMatrix = glm::rotate(rotationMatrix, Utils::DegreesToRadians(rotation.z), glm::vec3(0.0, 0.0, 1.0));

	UpdateTransform();
	UpdateUnitVectors();
}


void Transform::RotateXAxis(float angle)
{
	rotation.x += angle;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), Utils::DegreesToRadians(rotation.x), glm::vec3(1, 0, 0));

	UpdateUnitVectors();
	UpdateTransform();
}

void Transform::RotateYAxis(float angle)
{
	rotation.y += angle;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), Utils::DegreesToRadians(rotation.y), glm::vec3(0, 1, 0));

	UpdateTransform();
	UpdateUnitVectors();
}

void Transform::RotateZAxis(float angle)
{
	rotation.z += angle;
	rotationMatrix = glm::rotate(glm::mat4(1.0f), Utils::DegreesToRadians(rotation.z), glm::vec3(0, 0, 1));

	UpdateTransform();
	UpdateUnitVectors();
}


void Transform::SetScale(float scale)
{
	localScale.x = scale;
	localScale.y = scale;
	localScale.z = scale;
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(localScale.x, localScale.y, localScale.z));

	UpdateTransform();
}

void Transform::SetScale(Vector3 scale)
{
	localScale = scale;
	scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(localScale.x, localScale.y, localScale.z));

	UpdateTransform();
}


void Transform::Translate(Vector3 position) 
{
	this->position += position;
	translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(this->position.x, this->position.y, this->position.z));

	UpdateTransform();
}


void Transform::LookAt(Vector3 target) 
{
	LookAt(position, position + target, up);
}

void Transform::LookAt(Vector3 target, Vector3 upVector) 
{
	LookAt(position, position + target, upVector);
}

void Transform::LookAt(Vector3 position, Vector3 target, Vector3 upVector) 
{
	this->position = position;
	up = upVector;
	transform = glm::lookAt(glm::vec3(position.x, position.y, position.z), 
							glm::vec3(target.x, target.y, target.z), 
							glm::vec3(upVector.x, upVector.y, upVector.z));

	UpdateUnitVectors();
}

Vector3 Transform::GetFoward() const 
{
	return foward;
}

Vector3 Transform::GetRight() const 
{
	return right;
}

Vector3 Transform::GetPosition() const 
{
	return position;
}

Vector3 Transform::GetUp() const 
{
	return up;
}

Vector3 Transform::GetRotation() const 
{
	return rotation;
}

Vector3 Transform::GetScale() const 
{
	return localScale;
}

void Transform::operator *=(const Transform& otherTransform) 
{
	transform *= otherTransform.GetTransform();
}

Transform Transform::operator *(const Transform& otherTransform) const 
{
	Transform transform = *this;
	transform *= otherTransform;
	transform.position += otherTransform.position;
	return transform;
}

Vector3 Transform::operator *(const Vector3& otherVector) const
{
	glm::vec4 vec4 = glm::vec4(otherVector.x, otherVector.y, otherVector.z, 1.0f);
	glm::vec4 newVec4 = transform * vec4;

	return Vector3(newVec4.x, newVec4.y, newVec4.z);
}

glm::mat4 Transform::GetTransform() const 
{
	return transform;
}


void Transform::UpdateUnitVectors()
{
	const glm::vec3 newFoward = normalize(glm::vec3(transform[2]));
	foward = Vector3(newFoward.x, newFoward.y, newFoward.z);
	right = foward.Cross(Vector3::Up()).Normalize();
	up = right.Cross(foward).Normalize();
}

void Transform::UpdateTransform()
{
	transform = translationMatrix * rotationMatrix * scaleMatrix;
}