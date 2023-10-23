#pragma once

struct Vector
{
	float x;
	float y;
	float length;
};


class weapon {
private:
	Vector weaponVec;
	Vector baseVec;

	float collisionX, collisionY;

	float rot;				//��]
	float relativeRot;		//�v���C���[�̃x�N�g���𒆐S�Ƃ�����]

public:
	weapon();
	~weapon();

	void Update();
	void Draw() const;
};

