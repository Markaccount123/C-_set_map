#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


void test_set()
{
	//set最大的作用是排序+去重
	set<int> s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);
	s1.insert(7);
	s1.insert(9);
	s1.insert(5);
	s1.insert(7);
	//迭代器方式
	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//范围for方式
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	string strs[] = { "sort", "insert", "sort", "sort", "insert", "erase" };
	set<string> strunique;
	for (auto& s : strs)
	{
		strunique.insert(s);
	}
	//这时候你也可以感觉到，对于vector、list等来说，set、map他们的底层是完全不相同的，当时他们都可以使用迭代器进行遍历
	//所以说迭代器很好的屏蔽了上一层的细节


	for (auto& str : strunique)
	{
		cout << str << " ";
	}
	cout << endl;

	//去重的原理：首先快速的找到，看在不在，如果已经存在了，就不在进行插入了

	//这个是标准库里面的find函数 O（N）
	set<string>::iterator ret = std::find(strunique.begin(), strunique.end(),"sort");
	if (ret != strunique.end())
	{
		cout << "找到了" << endl;
	}
	
	//这个是set容器自带的find，那个效率更高一些？当然是自带的，因为这个是一个平衡二叉树（接近于满二叉树模型）的结构logN
	ret = strunique.find("sort");
	if (ret != strunique.end())
	{
		cout << "找到了" << endl;
	}
	//对于搜索树来说，增删查都可以，但是不能够改，因为你一旦修改了，他就不满足特性了

	//multiset最大的作用是排序，但是不去重
	//multiset<int> s2;
	//s2.insert(1);
	//s2.insert(3);
	//s2.insert(5);
	//s2.insert(7);
	//s2.insert(9);
	//s2.insert(5);
	//s2.insert(7);

	//set<int>::iterator it2 = s2.begin();
	//while (it2 != s2.end())
	//{
	//	cout << *it2 << " ";
	//	++it2;
	//}
	//cout << endl;
}



void test_map()
{
	//首先写一个字典
	//map<string, string> dict;
	//dict.insert(pair<string, string>("string", "字符串"));
	//dict.insert(pair<string, string>("sort", "排序"));

	//map<string, string>::iterator ret = dict.begin();
	////你会发现这样使用迭代器遍历是通过不了的，为什么呢？因为得到的迭代器ret是一个键值对,也就相当于一个结构体，里面有两个成员
	////一个是key，一个是value ,c++是不支持返回两个值的
	////while (ret != dict.end())
	////{
	////	cout << *ret << " ";
	////	++*ret;
	////}
	////cout << endl;‘


	//while (ret != dict.end())
	//{
	//	//cout <<(*ret).first<<(*ret).second<<" "; 但是结构体我们更喜欢使用->去访问
	//	cout << ret->first <<ret->second<< endl; //first 是Key值   second是Value值
	//	++ret;
	//}

	string strs[] = { "sort", "insert", "sort", "sort", "insert", "erase" };
	map<string, int> countMap;
	for (auto& s : strs)
	{
		//一定要先去查找
		auto ret = countMap.find(s);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			//countMap.insert(pair<string, int>("sort", 1));
			countMap.insert(make_pair(s,1));//更推荐这种写法，因为更加的简单,还需要在好好的理解一下make_pair，这是一个函数模板
		}
	}

	for (auto& e : countMap)
	{
		cout << e.first << ":"<<e.second << endl;
	}

	//for (auto& s : strs)
	//{
	//	countMap[s]++;//传的是Key,返回的是对应的Value
	//}


}


int main()
{
	//test_set();
	test_map();
	return 0;
}