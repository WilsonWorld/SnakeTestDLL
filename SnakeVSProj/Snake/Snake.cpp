#include "pch.h"
#include "Snake.h"


Snake::Snake(IntVector2 dir, int maxBodyPieceCount, IntVector2* snakeBody)
{
	m_SnakeBody = snakeBody;
    m_MovementDirection = dir;
    m_MaxBodyPieceCount = maxBodyPieceCount;
    m_BodyPieceCount = 1;
}

Snake::~Snake()
{

}

void Snake::SetNewDirection(IntVector2 newDirection)
{
    if (newDirection + m_SnakeBody[0] == m_SnakeBody[1])
        return;

    if (m_MovementDirection != newDirection)
    {
        m_MovementDirection = newDirection;
    }
}

bool Snake::UpdateBodyPosition()
{
    IntVector2 index = m_SnakeBody[0];
    IntVector2 newIndex = index + m_MovementDirection;

    for (int i = 2; i < m_BodyPieceCount; i++)
    {
        if (newIndex == m_SnakeBody[i])
        {
            return true;
        }
    }

    // Set new head position
    m_SnakeBody[0] = newIndex;
    // Update remaining body pieces
    for (int i = 1; i < m_BodyPieceCount; i++)
    {
        // Save current body position
        IntVector2 bodyIndex = m_SnakeBody[i];
        // Assign previous body position to the next cell
        m_SnakeBody[i] = index;
        // Pass position to the next body piece
        index = bodyIndex;
    }

    return false;
}

bool Snake::CheckForCollision(IntVector2 appleIndex)
{
    if (m_BodyPieceCount >= m_MaxBodyPieceCount)
        return false;

    return appleIndex == m_SnakeBody[0];
}

int Snake::Expand()
{
    IntVector2 lastCellIndex = IntVector2(0, 0);
    if (m_BodyPieceCount > 1)
    {
        lastCellIndex = m_SnakeBody[m_BodyPieceCount - 1];
    }
    else
    {
        lastCellIndex = m_SnakeBody[0];
    }

    lastCellIndex += m_MovementDirection * -1;

    m_SnakeBody[m_BodyPieceCount] = lastCellIndex;

    m_BodyPieceCount++;

    return m_BodyPieceCount;
}