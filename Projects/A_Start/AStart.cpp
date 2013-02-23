#include "stdafx.h" 
#include "AStart.h" 


AStart::AStart(int *mapInfo, int width, int height, int start, int goal) 
{ 
	Width  = width; 
	Height = height; 
	this->_startPoint  = start; 
	this->_targetPoint    = goal; 

	//�Ѷ�ά���鱣�浽һά������ȥ��������Ϣ�Ĵ��� 
	this->_mapInfo = new int[Width * Height]; 
	for (int i = 0; i < Width * Height; i++) 
	{ 
		//map[i] = mapInfo[i / width][i % width]; 
		this->_mapInfo[i] = mapInfo[i]; 
	} 

	//��¼ÿһ���ڵ��λ����Ϣ 
	this->_pointInfo = new Point[Width * Height]; 
	for (int i = 0; i < (Width * Height); i++) 
	{ 
		this->_pointInfo[i].x = i % Width; 
		this->_pointInfo[i].y = i / Width; 
	} 

	//��ʼ����� 
	this->_pointInfo[this->_startPoint].g_value = 0; 
	this->_pointInfo[this->_startPoint].h_value = get_h_value(this->_startPoint); 
	this->_pointInfo[this->_startPoint].parent = NULL; 

	//��������open_list�� 
	open_list.push_back(this->_startPoint); 
} 

AStart::~AStart() 
{ 
	if (this->_mapInfo != NULL) 
	{ 
		delete[] this->_mapInfo; 
	} 
	if (this->_pointInfo != NULL) 
	{ 
		delete[] this->_pointInfo; 
	} 
} 

int AStart::get_g_value(int pos) 
{ 
	//ֻ������������������ĸ��������ߣ����������gֵֻ��Ҫ�ڸ��ڵ��gֵ�ϼ�10 
	return (this->_pointInfo[pos].parent->g_value + 10); 
} 

int AStart::get_h_value(int pos) 
{ 
	//���ظõ㵽�յ��Manhattan���룬����10��Ϊ�˷����������� 
	return (10 * (abs(this->_targetPoint / Width - pos / Width) + abs(this->_targetPoint % Width - pos % Width))); 
} 

void AStart::getResultPath() 
{ 
	Point *temp = &this->_pointInfo[this->_targetPoint]; 
	while (temp != NULL) 
	{ 
		result.push_back(*temp); 
		temp = temp->parent; 
	} 
	return; 
} 

bool AStart::isReachable(int pos) 
{ 
	if ((pos / Width < Height) && (pos / Width >= 0) && 
		(pos % Width < Width)  && (pos % Width >= 0)) 
	{ 
		return true; 
	} 
	else 
	{ 
		return false; 
	} 
} 

//���pos���ɴ��������close_list���������������򣬽������²��� 
//���pos����open_list�������open_list�����ѵ�ǰ��������Ϊ���ĸ��� 
//���pos��open_list������g�Ĵ�С�������С������ĸ�������Ϊ��ǰ���� 
bool AStart::testRoad(int point, int cur) 
{ 
	if (isReachable(point)) 
	{ 
		if (point == this->_targetPoint) 
		{ 
			this->_pointInfo[point].parent = &this->_pointInfo[cur]; 
			return true; 
		} 
		if (this->_mapInfo[point] != 1) //1�����ϰ��0���ͨ�� 
		{ 
			if (close_list.end() == find(close_list.begin(), close_list.end(), point)) 
			{ 
				std::list<int>::iterator iter = find(open_list.begin(), open_list.end(), point); 
				if (iter == open_list.end()) 
				{ 
					open_list.push_back(point); 
					this->_pointInfo[point].parent = &this->_pointInfo[cur]; 
					this->_pointInfo[point].h_value = get_h_value(point); 
					this->_pointInfo[point].g_value = get_g_value(point); 
				} 
				else 
				{ 
					if ((this->_pointInfo[cur].g_value + 10) < this->_pointInfo[point].g_value) 
					{ 
						this->_pointInfo[point].parent = &this->_pointInfo[cur]; 
						this->_pointInfo[point].g_value = get_g_value(point); 
					} 
				} 
			} 
		} 
	} 
	return false; 
} 

bool AStart::Find() 
{ 
	//����open_list������Fֵ��С�Ľڵ���Ϊ��ǰҪ����Ľڵ� 
	//���open_listΪ�գ������û�н������ 
	if (open_list.empty()) 
	{ 
		return false; 
	} 

	int f_value = 0; 
	int min_f_value = -1; 
	std::list<int>::iterator iter, save; 
	for (iter = open_list.begin(); iter != open_list.end(); iter++) 
	{ 
		f_value = this->_pointInfo[*iter].g_value + this->_pointInfo[*iter].h_value; 
		//�����min==fҲ�����¸�����ֵ������open_list�п����Ԫ�ؾ��и��ߵ����ȼ� 
		//�����޹ؽ�Ҫ 
		if ((min_f_value == -1) || (min_f_value >= f_value)) 
		{ 
			min_f_value = f_value; 
			save = iter; 
		} 
	} 

	//�����Fֵ��С�Ľڵ��Ƶ�close_list�� 
	int cur = *save; 
	close_list.push_back(cur); 
	open_list.erase(save); 


	//�Ե�ǰ����������������ڷ�����в��� 
	//����յ������open_list����� 
	int up    = cur - Width; 
	int down  = cur + Width; 
	int left  = cur - 1; 
	int right = cur + 1; 
	if (true == testRoad(up, cur)) 
	{ 
		return true; 
	} 
	if (true == testRoad(down, cur)) 
	{ 
		return true; 
	} 
	if (true == testRoad(left, cur)) 
	{ 
		return true; 
	} 
	if (true == testRoad(right, cur)) 
	{ 
		return true; 
	} 

	return Find(); 
} 