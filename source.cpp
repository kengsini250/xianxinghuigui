#include <iostream>

float input[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f ,10.0f,11.0f };
float output[] = { 1.0f, 1.9f, 3.2f, 4.1f, 4.8f, 6.3f, 6.9f, 8.1f, 8.9f,10.1f,10.9f };
float k = 0.5f;
float b = 1.0f;

int MAX = 100;
float M = 0.05f;

float func(float x)
{
	return k * x + b;
}

float derivative()
{
	int count = sizeof(input) / sizeof(int);
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += (func(input[i]) - output[i])* input[i];
	}
	return sum/count;
}
void gradient()
{
	k = k - M * derivative();
	b = b - M * derivative();
}

int main()
{
	for (int i = 0; i < MAX; i++) {
		if (b > 0)
			std::cout << "y = " << k << "x + " << b << " \n";
		else
			std::cout << "y = " << k << "x " << b << " \n";

		gradient();
	}	
	if (b > 0)
		std::cout << "y = " << k << "x + " << b << " \n";
	else
		std::cout << "y = " << k << "x " << b << " \n";

	std::cout << "test x = 12 --> y =  "<< func(12.0f) << "\n";
	std::cout << "test x = 50 --> y =  "<< func(50.0f) << "\n";
	std::cout << "test x = 122 --> y =  "<< func(122.0f) << "\n";
}

