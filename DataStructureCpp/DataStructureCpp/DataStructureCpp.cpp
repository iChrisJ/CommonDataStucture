// DataStructureCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MaxHeap.h"
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <random>

#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"

using namespace std;

int main()
{

#pragma region MaxHeap test
	/*
	MaxHeap<int> maxheap = MaxHeap<int>(100);

	srand(time(NULL));
	for (int i = 0; i < 1; i++) {
		maxheap.insert(rand() % 100);
	}

	while (!maxheap.isEmpty())
		cout << maxheap.extractMax() << " ";
	cout << endl;
	*/

#pragma endregion MaxHeap test

#pragma region Binary search test
	/*
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words))
	{
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;

		// test BST
		time_t startTime = clock();
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
		{
			int *res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'god' : " << *bst.search("god") << endl;
		time_t endTime = clock();
		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		// test SST
		startTime = clock();
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
		{
			int *res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'god' : " << *sst.search("god") << endl;

		endTime = clock();
		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	}
	*/
#pragma endregion Binary search test

#pragma region Tree Traverse
	/*
	srand(time(NULL));
	BST<int, int> bst = BST<int, int>();

	int n = 100;
	for (int i = 0; i < n; i++)
	{
		int key = rand() % n;
		cout << key << " ";
		bst.insert(key, key);
	}
	cout << endl;

	// test size
	cout << "size: " << bst.size() << endl << endl;

	// test preOrder
	cout << "preOrder: " << endl;
	bst.preOrder();
	cout << endl << endl;

	// test inOrder
	cout << "inOrder: " << endl;
	bst.inOrder();
	cout << endl << endl;

	// test postOrder
	cout << "postOrder: " << endl;
	bst.postOrder();
	cout << endl << endl;

	// test levelOrder
	cout << "levelOrder: " << endl;
	bst.levelOrder();
	cout << endl << endl;
	*/
#pragma endregion Tree Traverse

#pragma region minimun and maximum
	/*
	srand(time(NULL));
	BST<int, int> bst = BST<int, int>();

	int n = 100;
	for (int i = 0; i < n; i++)
	{
		int key = rand() % n;
		cout << key << " ";
		bst.insert(key, key);
	}
	cout << endl;

	// minimum key
	cout << "minimum: " << bst.minimun() << endl;
	cout << endl;

	// maximum key
	cout << "maximum: " << bst.maximun() << endl;
	cout << endl;

	// test inOrder
	cout << "inOrder: " << endl;
	bst.inOrder();
	cout << endl << endl;

	// remove the max
	cout << "Remove the max" << endl;
	bst.removeMax();

	// remove the min
	cout << "Remove the min" << endl;
	bst.removeMin();

	// test inOrder
	cout << "inOrder: " << endl;
	bst.inOrder();
	cout << endl << endl;
	*/
#pragma endregion minimun and maximum

#pragma region Remove

	srand(time(NULL));
	BST<int, int> bst = BST<int, int>();

	int n = 10000;
	for (int i = 0; i < n; i++) {
		int key = rand() % n;
		// 为了后续测试方便,这里value值取和key值一样
		int value = key;
		//cout<<key<<" ";
		bst.insert(key, value);
	}

	// test remove
	// remove elements in random order
	int* order = new int[n];
	for (int i = 0; i < n; i++)
		order[i] = i;
	bst.shuffle(order, n);

	for (int i = 0; i < n; i++)
		if (bst.contains(order[i])) 
		{
			bst.remove(order[i]);
			cout << "After remove " << order[i] << " size = " << bst.size() << endl;
		}

#pragma endregion Remove
	return 0;
}

