#include "Shape.h"

Shape::Shape()
{
	//positions = //Vertices
	//{
	//	-0.5f, -0.5f, //vertex 0
	//	 0.5f, -0.5f, //vertex 1
	//	 0.5f,  0.5f, //vertex 2
	//	-0.5f,  0.5f  //vertex 3 for square
	//};
}

Shape::~Shape()
{

}

void Shape::SetPositions(float *arr){

	int size = *(&arr + 1) - arr;
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	std::cout << arrSize << std::endl;
}