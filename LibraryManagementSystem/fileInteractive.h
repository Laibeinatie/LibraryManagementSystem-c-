#pragma once
#include "TitleInfo.h"
#include<string>
#include<vector>
#include<fstream>
class fileInteractive : public TitleInfo
{
public:
	// ����ת�ַ���
	 string numberToString(int num);

	// �־û��ڴ棨ջ������д���ļ���
	 void writeTxt(vector <TitleInfo> books);

	// ͼ���ʼ�������ļ��ж�ȡ���ݣ�
	 vector <TitleInfo> readTxt();
};

