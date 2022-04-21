/*多继承的二义性问题*/
/*间接基类成员变量在派生类中有多份拷贝*/
/**#include<iostream>
using namespace std;
class Furntiure//定义Furniture类
{
public:
	Furntiure(string wood);//Furniture类构造函数
protected:
	string _wood;//表示材质
};
Furntiure::Furntiure(string wood)//类外实现构造函数
{
	_wood = wood;
}
class Sofa :public Furntiure//定义Sofa类公有继承Furniture类
{
public:
	Sofa(float length, string wood);//Sofa类的构造函数
protected:
	float _length;//表示长度
};
Sofa::Sofa(float length, string wood):Furntiure(wood)//类外实现构造函数
{
	_length = length;
}
class Bed :public Furntiure//定义类Bed公有继承Furniture类
{
public:
	Bed(float width, string wood);//Bed类构造函数
protected:
	float _width;//宽度
};
Bed::Bed( float width,string wood) :Furntiure(wood)//类外实现构造函数
{
	_width = width;
}
class Sofabed :public Sofa,public Bed//定义Sofabed类公有继承Sofa类和Bed类
{
public:
	Sofabed( float width, string wood1, float length, string wood2);//Sofabed类构造函数
	void getsize();//成员函数getsize（）获取沙发床的大小
};
Sofabed::Sofabed(float length, string wood1, float width, string wood2) :Sofa(length,wood1),Bed(width,wood2)
{
}
void Sofabed::getsize()
{
	cout << "沙发床的长为：" << _length << endl;
	cout << "沙发床的宽为：" << _width << endl;
	//cout << "沙发床的材质：" << _wood << endl;//产生了二义性
	cout << "沙发床的材质：" << Sofa::_wood << endl;//通过作用域限定符：：来解决二义性问题
	cout << "沙发床的材质：" << Bed::_wood << endl;
}
int main()
{
	Sofabed s1(2.1,"黄花木",1.1, "梨木");
	s1.getsize();
	return 0;
}***********************************************************/
/*虚继承
在虚继承中每个虚继承的派生类都会增加一个虚基类指针位于派生类对象的顶部，该指针指向一个
虚基类表，在表中记录了基类成员变量相对与虚指针的偏移量*/

/**#include<iostream>
using namespace std;
class Furntiure//定义Furniture类
{
public:
	Furntiure(string wood);//Furniture类构造函数
protected:
	string _wood;//表示材质
};
Furntiure::Furntiure(string wood)//类外实现构造函数
{
	_wood = wood;
}
class Sofa :virtual public Furntiure//定义Sofa类公有继承Furniture类//虚继承
{
public:
	Sofa(float length, string wood);//Sofa类的构造函数
protected:
	float _length;//表示长度
};
Sofa::Sofa(float length, string wood):Furntiure(wood)//类外实现构造函数
{
	_length = length;
}
class Bed :virtual public Furntiure//定义类Bed公有继承Furniture类//虚继承
{
public:
	Bed(float width, string wood);//Bed类构造函数
protected:
	float _width;//宽度
};
Bed::Bed( float width,string wood) :Furntiure(wood)//类外实现构造函数
{
	_width = width;
}
class Sofabed :public Sofa,public Bed//定义Sofabed类公有继承Sofa类和Bed类
{
public:
	Sofabed( float width, string wood1, float length, string wood2);//Sofabed类构造函数
	void getsize();//成员函数getsize（）获取沙发床的大小
};
Sofabed::Sofabed(float length, string wood1, float width, string wood2) :Sofa(length,wood1),Bed(width,wood2),Furntiure(wood1)
{
}
void Sofabed::getsize()
{
	cout << "沙发床的长为：" << _length << endl;
	cout << "沙发床的宽为：" << _width << endl;
	cout << "沙发床的材质：" << _wood << endl;//产生了二义性
	//cout << "沙发床的材质：" << Sofa::_wood << endl;//通过作用域限定符：：来解决二义性问题
	//cout << "沙发床的材质：" << Bed::_wood << endl;
}
int main()
{
	Sofabed s1(2.1,"黄花木",1.1, "梨木");
	s1.getsize();
	return 0;
}**************************/