#include<iostream>
#include<string>
using namespace std;
#define N 5  // ѧ������

#pragma pack(1)
struct student {
    char  name[8];
    short  age;
    float  score;
    char  remark[200];  // ��ע��Ϣ
};

student old_s[N];
student new_s[N];
char message[1250];


void input() {
	for (int i = 0; i < N; i++) {
		cout << "�������" << i + 1 << "��ѧ����������";
		cin >> old_s[i].name;
		cout << "�������" << i + 1 << "��ѧ�������䣺";
		cin >> old_s[i].age;
		cout << "�������" << i + 1 << "��ѧ���ĳɼ���";
		cin >> old_s[i].score;
		cout << "�������" << i + 1 << "��ѧ���ı�ע��Ϣ��";
		cin >> old_s[i].remark;
	}
}

void output() {
	for (int i = 0; i < N; i++) {
		cout << "��" << i + 1 << "��ѧ����������" << new_s[i].name << endl;
		cout << "��" << i + 1 << "��ѧ�������䣺" << new_s[i].age << endl;
		cout << "��" << i + 1 << "��ѧ���ĳɼ���" << new_s[i].score << endl;
		cout << "��" << i + 1 << "��ѧ���ı�ע��Ϣ��" << new_s[i].remark << endl;
	}
}

//sΪ��ѹ���������ʼ��ַ�� sno Ϊѹ�������� buf Ϊѹ���洢�����׵�ַ�����ؾ��ǵ��ú���ѹ������ֽ���
int pack_student_bytebybyte(student* s, int sno, char* buf) {
	int num = 0;

	for (int i = 0; i < sno; i++) {
		for (int namei = 0; namei < 8; namei++) {
			*buf = s[i].name[namei];
			buf++;
			num++;
			if (s[i].name[namei] == '\0') {
				break;
			}
		}

		for (int agei = 0; agei < sizeof(short); agei++) {
			*buf = ((char*)&(s[i].age))[agei];
			buf++;
			num++;
		}

		for (int scorei = 0; scorei < sizeof(float); scorei++) {
			*buf = ((char*)&(s[i].score))[scorei];
			buf++;
			num++;
		}

		for (int remarki = 0; remarki < 200; remarki++) {
			*buf = s[i].remark[remarki];
			buf++;
			num++;
			if (s[i].remark[remarki] == '\0') {
				break;
			}
		}
	}

	return num;
}
int  pack_student_whole(student* s, int sno, char* buf) {
	int num = 0;

	for (int i = 0; i < sno; i++) {
		strcpy(buf, s[i].name);
		buf += strlen(s[i].name);
		buf++;
		num += strlen(s[i].name);
		num++;

		*((short*)buf) = s[i].age;
		buf += sizeof(short);
		num += sizeof(short);

		*((float*)buf) = s[i].score;
		buf += sizeof(float);
		num += sizeof(float);

		strcpy(buf, s[i].remark);
		buf += strlen(s[i].remark);
		buf++;
		num += strlen(s[i].remark);
		num++;
	}

	return num;
}

//buf Ϊѹ������洢�����׵�ַ��lenΪbuf�д�����ݵĳ��ȣ�sΪ��Ž�ѹ���ݵĽṹ�������ʼ��ַ�����ؽ�ѹ������
int restore_student(char* buf, int len, student* s) {
	int num = 0;
	char* end = buf + len;

	for (int i = 0; i < N; i++) {
		if (buf >= end) {
			break;
		}

		strcpy(s[i].name, buf);
		buf += strlen(s[i].name);
		buf++;

		s[i].age = *((short*)buf);
		buf += sizeof(short);;

		s[i].score = *((float*)buf);
		buf += sizeof(float);

		strcpy(s[i].remark, buf);
		buf += strlen(s[i].remark);
		buf++;

		num++;
	}

	return num;
}

int main() {
	input();

	int num1 = pack_student_bytebybyte(old_s, 2, message);
	int num2 = pack_student_whole(&(old_s[2]), 3, &(message[num1]));
	
	//��ʮ�����Ƶ���ʽ�����message��ǰ40���ֽڵ����ݣ��������ʱ���ڴ洰�ڹ۲쵽��message��ǰ40���ֽڱȽ��Ƿ�һ��
	for (int i = 0; i < 40; i++) {
		printf("0x%02hhx   ", message[i]);
	}
	printf("\n");

	int num = num1 + num2;
	int person = restore_student(message, num, new_s);

	output();
	return 0;
}