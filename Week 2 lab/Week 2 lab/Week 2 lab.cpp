#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
	vector<int> lotteryNumber(0);
	vector<int>::iterator ip;
	random_device random;
	uniform_int_distribution<int> distribution(1, 50);

	int count = 0;
	while (count != 6)
	{
		auto lottNo = distribution(random);
		lotteryNumber.push_back(lottNo);
		count++;
	}

	sort(lotteryNumber.begin(), lotteryNumber.end());

	//testing if the random number generated correctly
		//for (ip = lotteryNumber.begin(); ip != lotteryNumber.end(); ++ip)
		//{
		//	cout << *ip << endl;
		//}

	vector<int> UserNumber(0);

	count = 1;
	int number;
	while (count != 7)
	{
		cout << "Input your " << count << " number please : ";
		cin >> number;
		if (std::find(UserNumber.begin(), UserNumber.end(), number) != UserNumber.end())
		{
			continue;
		}
		else
		{
			UserNumber.push_back(number);
			count++;

		}
	}

	//testing is the input number correctly saved
		//for (ip = UserNumber.begin(); ip != UserNumber.end(); ++ip)
		//{
		//	cout << *ip << endl;
		//}

		//vector<int>::iterator ip;
	int correctNo = 0;
	for (ip = lotteryNumber.begin(); ip != lotteryNumber.end(); ++ip)
	{
		if (std::find(UserNumber.begin(), UserNumber.end(), *ip) != UserNumber.end())
		{
			correctNo++;

		}
		else
		{
			continue;
		}
	}

	cout << "You match " << correctNo << " numbers!" << endl;
}