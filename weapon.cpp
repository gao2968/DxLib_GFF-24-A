#include "weapon.h"
#include "inputCtrl.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#define d_r(_d) _d * (M_PI / 180)
#define r_d(_r) _r * (180 / M_PI)


weapon::weapon()
{
	baseVec = { 100,0,100 };
	

	relativeRot = 90.0f;		//����ɂ���ĕς���
}

weapon::~weapon()
{
}

void weapon::Update()
{
	//debug
	int x = InputCtrl::GetMouseCursor().x;
	int y = InputCtrl::GetMouseCursor().y;
	int length = sqrt(x * x + y * y);

	float innerProduct = (x * baseVec.x) + (y * baseVec.y);
	float angle = acos(innerProduct / (length * baseVec.length));
	if (y > 0) {
		angle = (M_PI - angle);
		angle += M_PI;
	}


	relativeRot -= 4.0f;
	if (relativeRot < -90.0f) {
		relativeRot = 90.0f;
	}
	rot = -1 * (angle - (d_r(relativeRot)));

	collisionX = baseVec.x * cos((rot)) - baseVec.y * sin((rot)) + 640;
	collisionY = baseVec.x * sin((rot)) + baseVec.y * cos((rot)) + 360;

}

void weapon::Draw() const
{
	//debug
	int x = InputCtrl::GetMouseCursor().x - 640;
	int y = InputCtrl::GetMouseCursor().y - 360;


	DrawCircle(collisionX, collisionY, 3, 0xff0000, TRUE);
	
}

//��]�̌���
//r: �p�x(���W�A��)
//x : ����X���W
//y : ����Y���W

//X = x * cos(r) - y * sin(r)
//Y = x * sin(r) + y * cos(r)