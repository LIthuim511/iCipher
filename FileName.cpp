/*
* Copyright (c) 2021,����������ѧ�����ϵ�߼����Գ�����ƿγ���
* All rights reserved.
*
* �ļ����ƣ�link.cpp
* �ļ���ʶ�������ù���ƻ���
* ժ    Ҫ�����װ浥�������������Ԫ�ڵ�֮ǰ��һ��ͷ���
			��1�������������Ĵ������Լ����ӡ���ѯ��ɾ���ڵ㹦�ܣ�
			��2���������ļ�������
*
* ��ǰ�汾��1.0
* ��    �ߣ�������
* ������ڣ�2021��12��23��
*
* ȡ���汾����
* ԭ����  ��������
* ������ڣ�
*/

#include "link.h"

/// <summary>
/// ����һ��������ֻ��ͷ���
/// </summary>
/// <returns></returns>
Node* createLink() {
	// ���ڴ����ͷ���
	Node* head = new Node();

	// �ж��Ƿ�ɹ�������ڴ�
	if (head == NULL) {
		return NULL;
	}
	else {
		// ��һ���ڵ�ΪNULL
		head->next = NULL;
		return head;
	}
}

/// <summary>
/// ���������С
/// </summary>
/// <param name="head">����ͷָ��,ָ�볣����headֵ���䣬ָ����ڴ����ɱ�</param>
/// <returns>0��������</returns>
int getLinkSize(Node* const head) {
	if (head == NULL) {
		return -1;
	}

	//head = 0; �����

	// ������¼������
	int size = 0;
	// ��������β��
	Node* currNode = head;
	while (currNode->next != NULL) {
		currNode = currNode->next;
		size++;
	}

	return size;
}

/// <summary>
/// ������ͷ������һ���ڵ�
/// </summary>
/// <param name="head">����ͷָ��</param>
/// <param name="newElem">��Ԫ�أ�����ָ�룬��ַ����ɱ䣬��ֹ��ָ��ָ����ڴ������޸�</param>
/// <returns>1�������ɹ���������ʧ��</returns>
int addAtHead(Node* const head, const ElemType* newElem) {
	if (head == NULL) {
		return 0;
	}

	if (newElem == NULL) {
		return -1;
	}

	//newElem = 007;

	// �ڶ��ڴ�����ռ�
	Node* newNode = new Node();   //�½��½ڵ�

	if (newNode == NULL) {
		return -2;	//����ʧ��
	}
	else {
		//	��������
		newNode->data = *newElem;
		//newElem->score = 3;

		// ����ڵ�
		newNode->next = head->next;
		head->next = newNode;
		return 1;
	}
}

/// <summary>
/// ������β������һ���ڵ�
/// </summary>
/// <param name="head">����ͷָ�룬ָ�볣������ֹͷ����ַ���޸�</param>
/// <param name="newElem">��Ԫ�أ���ֹ��ָ��ָ����ڴ������޸�</param>
/// <returns>1�������ɹ���������ʧ��</returns>
int addAtTail(Node* const head, const  ElemType* newElem) {
	if (head == NULL) {
		return -1;
	}

	if (newElem == NULL) {
		return -2;
	}

	// �ڶ��ڴ�����ռ�
	Node* newNode = new Node();   //�½��½ڵ�

	if (newNode == NULL) {
		return -3;	//����ʧ��
	}
	else {
		//	��������
		newNode->data = *newElem;
		newNode->next = NULL;

		// ��������β��
		Node* currNode = head;
		while (currNode->next != NULL) {
			currNode = currNode->next;
		}

		// �����½ڵ�
		currNode->next = newNode;

		return 1;
	}
}

/// <summary>
/// ��������indexλ�õ�Ԫ�أ���ַ��
/// </summary>
/// <param name="head">����ͷָ�룬ָ�볣������ֹͷ����ַ���޸�</param>
/// <param name="index">λ��</param>
/// <returns>Ԫ�أ���ַ��</returns>
ElemType* getElemAt(Node* const head, int index) {
	if (head == NULL) {
		return NULL;
	}
	if (index < 0) {
		return NULL;
	}

	// ��ͷ��㣬������Ҫ��1 index++
	index++;		//	���� currNode = head->next;

	// ��������
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
/// ɾ������indexλ�õĽڵ�
/// </summary>
/// <param name="head">����ͷָ�룬ָ�볣������ֹͷ����ַ���޸�</param>
/// <param name="index">λ��</param>
/// <returns>1�������ɹ���������ʧ��</returns>
int delElemAt(Node* const head, int index) {
	if (head == NULL) {
		return 0;
	}
	if (index < 0) {
		return -1;
	}

	// ��������
	Node* pre = head;				// ��Զָ��currNode��ǰһ���ڵ�
	Node* currNode = head->next;	// ָ����Ҫ���ҵĽڵ�
	while ((index--) > 0) {
		if (currNode->next != NULL) {
			pre = currNode;				//	����pre
			currNode = currNode->next;	//	�ƶ�����һ���ڵ�
		}
		else {
			return -2;		//���޸ýڵ�
		}
	}

	// ɾ���ڵ�
	pre->next = currNode->next;

	// �����ڴ�
	delete currNode;

	return 1;
}
/*
* Copyright (c) 2021,����������ѧ�����ϵ�߼����Գ�����ƿγ���
* All rights reserved.
*
* �ļ����ƣ�������
* �ļ���ʶ�������ù���ƻ���
* ժ    Ҫ�����װ浥���������������---ģ���÷�
		   ��1�����ݽڵ㵥�����壬��public_def.h�С�
		   ��2��֧�ֵ�������
		   ��3���ɸ�����ƣ���������������Ϣ�޸�link.h�е�typedef  Student ElemType����

		   �������������²��ԣ�
		   ��1������Ĵ�����
		   ��2�����ݽڵ�������ͷ����β�������ӣ�
		   ��3�����������ȣ�
		   ��4������������ѯ�������õ�ַ��ֵ��Ч�ʸߣ���ɾ����
		   ��5����̬�������ݽڵ�ȹ��ܡ�
		   ����bug�뼴ʱ������maconi@126.com
*
* ��ǰ�汾��1.0
* ��    �ߣ�������
* ������ڣ�2021��12��24��
*
* ȡ���汾����
* ԭ����  ��������
* ������ڣ�
*/

#include <iostream>
#include <string.h>
#include "public_def.h"
#include "link.h"

using namespace std;

int main()
{
	//���������Ϣ��Ԥ���������ݽṹ��
	Student s1 = { 1 , "zhangsan" , 'M' , 95.5 };
	Student s2 = { 2 , "lisi" , 'F' , 80 };
	Student s3 = { 3 , "wangwu" , 'F' , 97 };

	// ��������
	Node* newLink = createLink();

	// s1��������Ԫ
	int ret = addAtHead(newLink, &s1);

	// �жϽ��
	if (ret == 1) {
		cout << "zhangsan��������ͷ���ɹ���addAtHead" << endl;
	}

	// �ײ������ڵ�
	ret = addAtHead(newLink, &s2);
	// �жϽ��
	if (ret == 1) {
		cout << "lisi��������ͷ���ɹ���addAtHead" << endl;
	}

	// β�������ڵ�
	ret = addAtTail(newLink, &s3);
	if (ret == 1) {
		cout << "wangwu��������β���ɹ���addAtTail" << endl;
	}

	// ����������
	int count = getLinkSize(newLink);

	// ѭ���ӡ����
	cout << "ѭ���ӡ����" << endl;
	for (size_t i = 0; i < count; i++)
	{
		Student* student = getElemAt(newLink, i);
		if (student != NULL) {
			Student stu = *student;		// ��������
			cout << stu.name << endl;
		}
	}

	// ����2��ѧ��
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

			// ��¼2#ѧ�����
			del_index = i;
		}

	}

	// ɾ��2��ѧ�� ����
	cout << "ɾ��2��ѧ�� ����" << endl;
	ret = delElemAt(newLink, del_index);
	if (ret == 1) {
		cout << "ɾ��2��ѧ��lisi�ɹ���" << endl;
	}

	// ������̬�ڵ�
	Student* newStu = new Student;
	newStu->no = 4;
	strcpy(newStu->name, "Qin");
	newStu->sex = 'M';
	newStu->score = 99.9;


	ret = addAtTail(newLink, newStu);
	if (ret == 1) {
		cout << "Qin��������β���ɹ���addAtTail" << endl;
	}

	// ѭ���ӡ����
	for (size_t i = 0; i < count; i++)
	{
		Student* student = getElemAt(newLink, i);
		if (student != NULL) {
			Student stu = *student;		// ��������
			cout << stu.name << endl;
		}
	}

	cout << endl << "GameOver";

}

