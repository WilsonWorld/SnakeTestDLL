#include "pch.h"
#include "SnakeAPI.h"
#include "Snake.h"


PLUGIN_API void* Snake_Create(CIntVector2 movementDirection, int maxBodyPieceCount, CIntVector2* snakeBody)
{
    return new Snake(IntVector2(movementDirection.x, movementDirection.y), maxBodyPieceCount, (IntVector2*)snakeBody);
}

PLUGIN_API void Snake_Destroy(void* snakePtr)
{
    Snake* snake = static_cast<Snake*>(snakePtr);

    if (snake != nullptr)
    {
        delete snake;
        snake = nullptr;
    }
}

PLUGIN_API void Snake_SetNewDirection(CIntVector2 newDirection, void* snakePtr)
{
    Snake* snake = static_cast<Snake*>(snakePtr);
    snake->SetNewDirection(IntVector2(newDirection.x, newDirection.y));
}

PLUGIN_API bool Snake_UpdateBodyPosition(void* snakePtr)
{
    Snake* snake = static_cast<Snake*>(snakePtr);
    return snake->UpdateBodyPosition();
}

PLUGIN_API bool Snake_CheckForCollision(CIntVector2 appleIndex, void* snakePtr)
{
    Snake* snake = static_cast<Snake*>(snakePtr);
    return snake->CheckForCollision(IntVector2(appleIndex.x, appleIndex.y));
}

PLUGIN_API int Snake_Expand(void* snakePtr)
{
    Snake* snake = static_cast<Snake*>(snakePtr);
    return snake->Expand();
}