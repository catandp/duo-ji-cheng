/*��̳еĶ���������*/
/*��ӻ����Ա���������������ж�ݿ���*/
/**#include<iostream>
using namespace std;
class Furntiure//����Furniture��
{
public:
	Furntiure(string wood);//Furniture�๹�캯��
protected:
	string _wood;//��ʾ����
};
Furntiure::Furntiure(string wood)//����ʵ�ֹ��캯��
{
	_wood = wood;
}
class Sofa :public Furntiure//����Sofa�๫�м̳�Furniture��
{
public:
	Sofa(float length, string wood);//Sofa��Ĺ��캯��
protected:
	float _length;//��ʾ����
};
Sofa::Sofa(float length, string wood):Furntiure(wood)//����ʵ�ֹ��캯��
{
	_length = length;
}
class Bed :public Furntiure//������Bed���м̳�Furniture��
{
public:
	Bed(float width, string wood);//Bed�๹�캯��
protected:
	float _width;//���
};
Bed::Bed( float width,string wood) :Furntiure(wood)//����ʵ�ֹ��캯��
{
	_width = width;
}
class Sofabed :public Sofa,public Bed//����Sofabed�๫�м̳�Sofa���Bed��
{
public:
	Sofabed( float width, string wood1, float length, string wood2);//Sofabed�๹�캯��
	void getsize();//��Ա����getsize������ȡɳ�����Ĵ�С
};
Sofabed::Sofabed(float length, string wood1, float width, string wood2) :Sofa(length,wood1),Bed(width,wood2)
{
}
void Sofabed::getsize()
{
	cout << "ɳ�����ĳ�Ϊ��" << _length << endl;
	cout << "ɳ�����Ŀ�Ϊ��" << _width << endl;
	//cout << "ɳ�����Ĳ��ʣ�" << _wood << endl;//�����˶�����
	cout << "ɳ�����Ĳ��ʣ�" << Sofa::_wood << endl;//ͨ���������޶����������������������
	cout << "ɳ�����Ĳ��ʣ�" << Bed::_wood << endl;
}
int main()
{
	Sofabed s1(2.1,"�ƻ�ľ",1.1, "��ľ");
	s1.getsize();
	return 0;
}***********************************************************/
/*��̳�
����̳���ÿ����̳е������඼������һ�������ָ��λ�����������Ķ�������ָ��ָ��һ��
�������ڱ��м�¼�˻����Ա�����������ָ���ƫ����*/

/**#include<iostream>
using namespace std;
class Furntiure//����Furniture��
{
public:
	Furntiure(string wood);//Furniture�๹�캯��
protected:
	string _wood;//��ʾ����
};
Furntiure::Furntiure(string wood)//����ʵ�ֹ��캯��
{
	_wood = wood;
}
class Sofa :virtual public Furntiure//����Sofa�๫�м̳�Furniture��//��̳�
{
public:
	Sofa(float length, string wood);//Sofa��Ĺ��캯��
protected:
	float _length;//��ʾ����
};
Sofa::Sofa(float length, string wood):Furntiure(wood)//����ʵ�ֹ��캯��
{
	_length = length;
}
class Bed :virtual public Furntiure//������Bed���м̳�Furniture��//��̳�
{
public:
	Bed(float width, string wood);//Bed�๹�캯��
protected:
	float _width;//���
};
Bed::Bed( float width,string wood) :Furntiure(wood)//����ʵ�ֹ��캯��
{
	_width = width;
}
class Sofabed :public Sofa,public Bed//����Sofabed�๫�м̳�Sofa���Bed��
{
public:
	Sofabed( float width, string wood1, float length, string wood2);//Sofabed�๹�캯��
	void getsize();//��Ա����getsize������ȡɳ�����Ĵ�С
};
Sofabed::Sofabed(float length, string wood1, float width, string wood2) :Sofa(length,wood1),Bed(width,wood2),Furntiure(wood1)
{
}
void Sofabed::getsize()
{
	cout << "ɳ�����ĳ�Ϊ��" << _length << endl;
	cout << "ɳ�����Ŀ�Ϊ��" << _width << endl;
	cout << "ɳ�����Ĳ��ʣ�" << _wood << endl;//�����˶�����
	//cout << "ɳ�����Ĳ��ʣ�" << Sofa::_wood << endl;//ͨ���������޶����������������������
	//cout << "ɳ�����Ĳ��ʣ�" << Bed::_wood << endl;
}
int main()
{
	Sofabed s1(2.1,"�ƻ�ľ",1.1, "��ľ");
	s1.getsize();
	return 0;
}**************************/