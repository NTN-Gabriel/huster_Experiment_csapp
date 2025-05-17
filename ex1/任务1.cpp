#include<iostream>
#include<string>
using namespace std;
#define N 5  // 学生人数

#pragma pack(1)
struct student {
    char  name[8];
    short  age;
    float  score;
    char  remark[200];  // 备注信息
};

student old_s[N];
student new_s[N];
char message[1250];


void input() {
	for (int i = 0; i < N; i++) {
		cout << "请输入第" << i + 1 << "个学生的姓名：";
		cin >> old_s[i].name;
		cout << "请输入第" << i + 1 << "个学生的年龄：";
		cin >> old_s[i].age;
		cout << "请输入第" << i + 1 << "个学生的成绩：";
		cin >> old_s[i].score;
		cout << "请输入第" << i + 1 << "个学生的备注信息：";
		cin >> old_s[i].remark;
	}
}

void output() {
	for (int i = 0; i < N; i++) {
		cout << "第" << i + 1 << "个学生的姓名：" << new_s[i].name << endl;
		cout << "第" << i + 1 << "个学生的年龄：" << new_s[i].age << endl;
		cout << "第" << i + 1 << "个学生的成绩：" << new_s[i].score << endl;
		cout << "第" << i + 1 << "个学生的备注信息：" << new_s[i].remark << endl;
	}
}

//s为待压缩数组的起始地址； sno 为压缩人数； buf 为压缩存储区的首地址；返回均是调用函数压缩后的字节数
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

//buf 为压缩区域存储区的首地址；len为buf中存放数据的长度；s为存放解压数据的结构数组的起始地址；返回解压的人数
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
	
	//以十六进制的形式，输出message的前40个字节的内容，并与调试时在内存窗口观察到的message的前40个字节比较是否一致
	for (int i = 0; i < 40; i++) {
		printf("0x%02hhx   ", message[i]);
	}
	printf("\n");

	int num = num1 + num2;
	int person = restore_student(message, num, new_s);

	output();
	return 0;
}