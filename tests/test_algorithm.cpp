#include "test_algorithm.hpp"

void test_std_equal()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec1(&arr[0], &arr[5]);
	std::vector<int> vec2(&arr[0], &arr[5]);

	assert(
		std::equal(
			vec1.begin(),
			vec1.end(),
			vec2.begin()
		) == true
	);
	assert(
		std::equal(
			vec1.begin(),
			vec1.end(),
			vec2.begin(),
			myPredicate<int>
		) == true
	);
}

void test_ft_equal()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec1(&arr[0], &arr[5]);
	std::vector<int> vec2(&arr[0], &arr[5]);

	assert(
		ft::equal(
			vec1.begin(),
			vec1.end(),
			vec2.begin()
		) == true
	);
	assert(
		ft::equal(
			vec1.begin(),
			vec1.end(),
			vec2.begin(),
			myPredicate<int>
		) == true
	);
}
