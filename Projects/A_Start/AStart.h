////////////////////////////////////////////////////////////////////////////////////// 
// 
//  FileName    :   A.h 
//  Version     :   1.0 
//  Creater     :   Ranger Cai 
//  Date        :   2012-2-27 09:44:49 
//  Comment     :   A* algorithm header file 
// 
////////////////////////////////////////////////////////////////////////////////////// 
#ifndef _A_FINDPATH_H 
#define _A_FINDPATH_H 

#include <list> 
#include <algorithm> 

//��¼��ͼ��ÿ���ڵ��λ����Ϣ�Լ���ֵ��Ϣ�Ľṹ���ջ 
typedef struct _Point 
{ 
	int x; 
	int y; 
	int h_value;  //hֵΪ�ڵ㵽�յ��Manhattan���� 
	int g_value;  //gֵΪ��㵽�õ���ƶ����� 
	struct _Point *parent;  //ָ�򸸽ڵ� 
}Point; 

class AStart 
{ 
public: 
	//��ʼ�������ͼ��ά���顢��ͼ��������ʼ���յ��������е���� 
	AStart(int *mapInfo, int width, int height, int start, int end); 
	~AStart(); 

	//A*���ң����ҳɹ�����true�����򷵻�false 
	bool Find(); 
	//���Find()�����ɹ�������Ե��ô˺����ѽ��·�����뵽result�� 
	void getResultPath(); 

	//����pos�ڵ��gֵ 
	int get_g_value(int pos); 
	//����pos�ڵ��hֵ 
	int get_h_value(int pos); 
	//�ж�pos�ڵ��Ƿ��ڵ�ͼ�� 
	bool isReachable(int pos); 
	//���Խڵ��Ƿ���ò��ж��Ƿ��Ѿ��ҵ�·�� 
	bool testRoad(int pos, int cur); 

	int  *_mapInfo;  //��ͼ��Ϣ 
	Point *_pointInfo; //���ӽڵ��ϵ�� 
	std::list<Point> result;  //���ҳɹ���Ľ��·�������ڴ� 

private: 
	int Width; 
	int Height; 
	int _startPoint; 
	int _targetPoint; 

	std::list<int> open_list;   //open���еĽڵ�Ϊ�����Ľڵ� 
	std::list<int> close_list;  //close���еĽڵ�Ϊ��ʱ����ע�Ľڵ� 
}; 

#endif //_A_FINDPATH_H 