#include <iostream>
#include <algorithm>   // 배열(알고리즘) 에서 숫자 뽑기
#include <vector>      // 배열같은놈
#include <iterator>		
#include <numeric>		

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::copy_if;
using std::find;
using std::find_if;
using std::equal;
using std::back_inserter;
using std::search;
using std::accumulate;
using std::transform;
using std::remove;
using std::remove_if;

bool isEven(int data)
{
	return (data % 2 == 0);   
}
bool isSize(int data)              // 구조체 3개를 만든다
{
	return data == 6;
}
int square(int data)
{
	return data * data;
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5};           // 구조체에 들어가는 배열을 만든다
	vector<int> nums(arr, arr + 5);

	int arr2[] = {6, 7, 8, 9, 10};        // 구조체에 들어가는 배열2 를 만든다
	vector<int> nums2(arr2, arr2 + 5);

//	for (vector<int>::const_iterator i = nums2.begin(); iter != nums2.cend(), ++iter) {
//		nums.push_back(*iter);
//	}
	//nums.insert(nums.end(), nums2.cbegin(), nums2.cend());

	copy(nums2.cbegin(), nums2.cend(), back_inserter(nums));              // 배열을 복사  < copy >
	copy_if(nums2.cbegin(), nums2.cend(), back_inserter(nums),isEven);   // 뒤에다 붙혀 준다

	for (vector<int>::const_iterator iter = nums.begin(); iter != nums.cend();  ++iter) { 
		cout << *iter;
	}
	cout << endl;

	find(nums.cbegin(), nums.cend(), 10);

	vector<int>::const_iterator iter = find(nums.cbegin(), nums.cend(), 10);
	if (iter != nums.cend())
		cout << " find found " << endl;
	else
		cout << " find not found " << endl;

	//vector<int>::const_iterator iter = find_if(nums.cbegin(), nums2.cend(), isSize);

	vector<int> nums3 = nums;
	if ( equal(nums. cbegin(), nums.cend(), nums3.cbegin()))
		cout << " find found " << endl;
	else
		cout << " find not found" << endl;

	int arr3[] = { 3,4,6 };                                         // 배열 3을 만든다
	iter = search(nums.cbegin(), nums.cend(), arr3, arr3 + 1);
	//cout << "숫자 뽑아라~~" << *iter << endl;
	if (iter != nums.cend())
		cout << "search found" << endl;
	else
		cout << "search not found " << endl;

	double average = static_cast <double>(nums.cbegin(), nums.cend(), 0) / nums.size();

	vector<int> reault;
	//for (vector<int>::const_iterator iter = nums.cbegin(); iter != nums.cand(); ++iter) {
    //reault.push_back(*iter * *iter); }

	transform(nums.cbegin(), nums.cend(), back_inserter(reault),square);
	for (vector<int>::const_iterator iter = nums.cbegin(); iter != nums.cend(); ++iter) {
		//reault.push_back(*iter * *iter);
		cout << *iter;
	}

	//vector<int>::iterator iter2 = remove(nums.begin(), nums.end(), 3);
	
	remove_if(nums.begin(), nums.end(), isEven);
	for (vector<int>::const_iterator iter = nums.cbegin(); iter != nums.cend(); ++iter) {
		cout << *iter;
	}
	cout << endl;

	return 0;
}
