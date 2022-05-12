#pragma once


class Snake
{
public:
    Snake(IntVector2 movementDirection, int maxBodyPieceCount, IntVector2* snakeBody);

    virtual ~Snake();

    void SetNewDirection(IntVector2 newDirection);

    bool UpdateBodyPosition();

    bool CheckForCollision(IntVector2 appleIndex);

    int Expand();

private:
    IntVector2* m_SnakeBody;
    IntVector2 m_MovementDirection;

    int m_BodyPieceCount;
    int m_MaxBodyPieceCount;
};

