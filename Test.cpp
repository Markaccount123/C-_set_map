#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


void test_set()
{
	//set��������������+ȥ��
	set<int> s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(5);
	s1.insert(7);
	s1.insert(9);
	s1.insert(5);
	s1.insert(7);
	//��������ʽ
	set<int>::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//��Χfor��ʽ
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
	//��ʱ����Ҳ���Ըо���������vector��list����˵��set��map���ǵĵײ�����ȫ����ͬ�ģ���ʱ���Ƕ�����ʹ�õ��������б���
	//����˵�������ܺõ���������һ���ϸ��


	for (auto& str : strunique)
	{
		cout << str << " ";
	}
	cout << endl;

	//ȥ�ص�ԭ�����ȿ��ٵ��ҵ������ڲ��ڣ�����Ѿ������ˣ��Ͳ��ڽ��в�����

	//����Ǳ�׼�������find���� O��N��
	set<string>::iterator ret = std::find(strunique.begin(), strunique.end(),"sort");
	if (ret != strunique.end())
	{
		cout << "�ҵ���" << endl;
	}
	
	//�����set�����Դ���find���Ǹ�Ч�ʸ���һЩ����Ȼ���Դ��ģ���Ϊ�����һ��ƽ����������ӽ�����������ģ�ͣ��ĽṹlogN
	ret = strunique.find("sort");
	if (ret != strunique.end())
	{
		cout << "�ҵ���" << endl;
	}
	//������������˵����ɾ�鶼���ԣ����ǲ��ܹ��ģ���Ϊ��һ���޸��ˣ����Ͳ�����������

	//multiset�������������򣬵��ǲ�ȥ��
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
	//����дһ���ֵ�
	//map<string, string> dict;
	//dict.insert(pair<string, string>("string", "�ַ���"));
	//dict.insert(pair<string, string>("sort", "����"));

	//map<string, string>::iterator ret = dict.begin();
	////��ᷢ������ʹ�õ�����������ͨ�����˵ģ�Ϊʲô�أ���Ϊ�õ��ĵ�����ret��һ����ֵ��,Ҳ���൱��һ���ṹ�壬������������Ա
	////һ����key��һ����value ,c++�ǲ�֧�ַ�������ֵ��
	////while (ret != dict.end())
	////{
	////	cout << *ret << " ";
	////	++*ret;
	////}
	////cout << endl;��


	//while (ret != dict.end())
	//{
	//	//cout <<(*ret).first<<(*ret).second<<" "; ���ǽṹ�����Ǹ�ϲ��ʹ��->ȥ����
	//	cout << ret->first <<ret->second<< endl; //first ��Keyֵ   second��Valueֵ
	//	++ret;
	//}

	string strs[] = { "sort", "insert", "sort", "sort", "insert", "erase" };
	map<string, int> countMap;
	for (auto& s : strs)
	{
		//һ��Ҫ��ȥ����
		auto ret = countMap.find(s);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			//countMap.insert(pair<string, int>("sort", 1));
			countMap.insert(make_pair(s,1));//���Ƽ�����д������Ϊ���ӵļ�,����Ҫ�ںúõ����һ��make_pair������һ������ģ��
		}
	}

	for (auto& e : countMap)
	{
		cout << e.first << ":"<<e.second << endl;
	}

	//for (auto& s : strs)
	//{
	//	countMap[s]++;//������Key,���ص��Ƕ�Ӧ��Value
	//}


}


int main()
{
	//test_set();
	test_map();
	return 0;
}