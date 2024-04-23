/*
* Copyright (c) 2021,华北电力大学计算机系高级语言程序设计课程组
* All rights reserved.
*
* 文件名称：link.cpp
* 文件标识：见配置管理计划书
* 摘    要：简易版单向链表，链表的首元节点之前有一个头结点
			（1）仅仅完成链表的创建，以及增加、查询、删除节点功能；
			（2）完成链表的计数功能
*
* 当前版本：1.0
* 作    者：王晓辉
* 完成日期：2021年12月23日
*
* 取代版本：无
* 原作者  ：王晓辉
* 完成日期：
*/

#include "link.h"

/// <summary>
/// 创建一个空链表，只有头结点
/// </summary>
/// <returns></returns>
Node* createLink() {
	// 堆内存分配头结点
	Node* head = new Node();

	// 判断是否成功申请堆内存
	if (head == NULL) {
		return NULL;
	}
	else {
		// 下一个节点为NULL
		head->next = NULL;
		return head;
	}
}

/// <summary>
/// 计算链表大小
/// </summary>
/// <param name="head">链表头指针,指针常量：head值不变，指向的内存区可变</param>
/// <returns>0：空链表</returns>
int getLinkSize(Node* const head) {
	if (head == NULL) {
		return -1;
	}

	//head = 0; 错误的

	// 遍历记录链表长度
	int size = 0;
	// 查找链表尾部
	Node* currNode = head;
	while (currNode->next != NULL) {
		currNode = currNode->next;
		size++;
	}

	return size;
}

/// <summary>
/// 在链表头部增加一个节点
/// </summary>
/// <param name="head">链表头指针</param>
/// <param name="newElem">新元素，常量指针，地址本身可变，防止该指针指向的内存区被修改</param>
/// <returns>1：新增成功；其它：失败</returns>
int addAtHead(Node* const head, const ElemType* newElem) {
	if (head == NULL) {
		return 0;
	}

	if (newElem == NULL) {
		return -1;
	}

	//newElem = 007;

	// 在堆内存申请空间
	Node* newNode = new Node();   //新建新节点

	if (newNode == NULL) {
		return -2;	//申请失败
	}
	else {
		//	复制数据
		newNode->data = *newElem;
		//newElem->score = 3;

		// 插入节点
		newNode->next = head->next;
		head->next = newNode;
		return 1;
	}
}

/// <summary>
/// 在链表尾部插入一个节点
/// </summary>
/// <param name="head">链表头指针，指针常量：防止头结点地址被修改</param>
/// <param name="newElem">新元素，防止该指针指向的内存区被修改</param>
/// <returns>1：新增成功；其它：失败</returns>
int addAtTail(Node* const head, const  ElemType* newElem) {
	if (head == NULL) {
		return -1;
	}

	if (newElem == NULL) {
		return -2;
	}

	// 在堆内存申请空间
	Node* newNode = new Node();   //新建新节点

	if (newNode == NULL) {
		return -3;	//申请失败
	}
	else {
		//	复制数据
		newNode->data = *newElem;
		newNode->next = NULL;

		// 查找链表尾部
		Node* currNode = head;
		while (currNode->next != NULL) {
			currNode = currNode->next;
		}

		// 插入新节点
		currNode->next = newNode;

		return 1;
	}
}

/// <summary>
/// 查找链表index位置的元素（地址）
/// </summary>
/// <param name="head">链表头指针，指针常量：防止头结点地址被修改</param>
/// <param name="index">位置</param>
/// <returns>元素（地址）</returns>
ElemType* getElemAt(Node* const head, int index) {
	if (head == NULL) {
		return NULL;
	}
	if (index < 0) {
		return NULL;
	}

	// 有头结点，计数需要加1 index++
	index++;		//	或者 currNode = head->next;

	// 查找链表
	Node* currNode = head;
	while (index--) {
		if (currNode->next != NULL) {
			currNode = currNode->next;
		}
		else {
			return NULL;
		}
	}

	return &(currNode->data);
}

/// <summary>
/// 删除链表index位置的节点
/// </summary>
/// <param name="head">链表头指针，指针常量：防止头结点地址被修改</param>
/// <param name="index">位置</param>
/// <returns>1：操作成功；其它：失败</returns>
int delElemAt(Node* const head, int index) {
	if (head == NULL) {
		return 0;
	}
	if (index < 0) {
		return -1;
	}

	// 查找链表
	Node* pre = head;				// 永远指向currNode的前一个节点
	Node* currNode = head->next;	// 指向需要查找的节点
	while ((index--) > 0) {
		if (currNode->next != NULL) {
			pre = currNode;				//	更新pre
			currNode = currNode->next;	//	移动到下一个节点
		}
		else {
			return -2;		//查无该节点
		}
	}

	// 删除节点
	pre->next = currNode->next;

	// 回收内存
	delete currNode;

	return 1;
}
/*
* Copyright (c) 2021,华北电力大学计算机系高级语言程序设计课程组
* All rights reserved.
*
* 文件名称：主程序
* 文件标识：见配置管理计划书
* 摘    要：简易版单向链表测试主程序---模板用法
		   （1）数据节点单独定义，在public_def.h中。
		   （2）支持单向链表；
		   （3）可复用设计，更换链表数据信息修改link.h中的typedef  Student ElemType即可

		   本程序做了如下测试：
		   （1）链表的创建；
		   （2）数据节点在链表头部、尾部的增加；
		   （3）计算链表长度；
		   （4）遍历链表、查询链表（采用地址传值，效率高）、删除；
		   （5）动态新增数据节点等功能。
		   如有bug请即时反馈：maconi@126.com
*
* 当前版本：1.0
* 作    者：王晓辉
* 完成日期：2021年12月24日
*
* 取代版本：无
* 原作者  ：王晓辉
* 完成日期：
*/

#include <iostream>
#include <string.h>
#include "public_def.h"
#include "link.h"

using namespace std;

int main()
{
	//创建结点信息，预备三个数据结构体
	Student s1 = { 1 , "zhangsan" , 'M' , 95.5 };
	Student s2 = { 2 , "lisi" , 'F' , 80 };
	Student s3 = { 3 , "wangwu" , 'F' , 97 };

	// 创建队列
	Node* newLink = createLink();

	// s1放链表首元
	int ret = addAtHead(newLink, &s1);

	// 判断结果
	if (ret == 1) {
		cout << "zhangsan插入链表头部成功，addAtHead" << endl;
	}

	// 首部新增节点
	ret = addAtHead(newLink, &s2);
	// 判断结果
	if (ret == 1) {
		cout << "lisi插入链表头部成功，addAtHead" << endl;
	}

	// 尾部新增节点
	ret = addAtTail(newLink, &s3);
	if (ret == 1) {
		cout << "wangwu插入链表尾部成功，addAtTail" << endl;
	}

	// 计算链表长度
	int count = getLinkSize(newLink);

	// 循序打印链表
	cout << "循序打印链表" << endl;
	for (size_t i = 0; i < count; i++)
	{
		Student* student = getElemAt(newLink, i);
		if (student != NULL) {
			Student stu = *student;		// 拷贝数据
			cout << stu.name << endl;
		}
	}

	// 查找2号学生
	int del_index = -1;
	for (size_t i = 0; i < count; i++)
	{
		Student* student = getElemAt(newLink, i);
		if (student != NULL && student->no == 2) {
			cout << "SNO:" << student->no;
			cout << "  name:" << student->name;
			cout << "  sex:" << student->sex;
			cout << "  score:" << student->score;
			cout << endl;

			// 记录2#学生序号
			del_index = i;
		}

	}

	// 删除2号学生 李四
	cout << "删除2号学生 李四" << endl;
	ret = delElemAt(newLink, del_index);
	if (ret == 1) {
		cout << "删除2号学生lisi成功。" << endl;
	}

	// 新增动态节点
	Student* newStu = new Student;
	newStu->no = 4;
	strcpy(newStu->name, "Qin");
	newStu->sex = 'M';
	newStu->score = 99.9;


	ret = addAtTail(newLink, newStu);
	if (ret == 1) {
		cout << "Qin插入链表尾部成功，addAtTail" << endl;
	}

	// 循序打印链表
	for (size_t i = 0; i < count; i++)
	{
		Student* student = getElemAt(newLink, i);
		if (student != NULL) {
			Student stu = *student;		// 拷贝数据
			cout << stu.name << endl;
		}
	}

	cout << endl << "GameOver";

}

