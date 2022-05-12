using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public class SnakeGlue : IDisposable
{
    public SnakeGlue(IntVector2 movementDirection, int maxBodyPieceCount, IntVector2[] snakeBody)
    {
        Impl = Snake_Create(movementDirection, maxBodyPieceCount, snakeBody);
    }

    public void Dispose()
    {
        Snake_Destroy(Impl);
    }

    public void SetNewDirection(IntVector2 newDirection)
    {
        Snake_SetNewDirection(newDirection, Impl);
    }

    public bool UpdateBodyPosition()
    {
        return Snake_UpdateBodyPosition(Impl);
    }

    public bool CheckForCollision(IntVector2 appleIndex)
    {
        return Snake_CheckForCollision(appleIndex, Impl);
    }

    public int Expand()
    {
        return Snake_Expand(Impl);
    }

    public IntPtr Impl { get; private set; }

    [DllImport("SnakePlugin")]
    static extern IntPtr Snake_Create(IntVector2 movementDirection, int maxBodyPieceCount, [MarshalAs(UnmanagedType.SafeArray)] IntVector2[] snakeBody);

    [DllImport("SnakePlugin")]
    static extern void Snake_Destroy(IntPtr snakePtr);

    [DllImport("SnakePlugin")]
    static extern void Snake_SetNewDirection(IntVector2 newDirection, IntPtr snakePtr);

    [DllImport("SnakePlugin")]
    [return: MarshalAs(UnmanagedType.I1)]
    static extern bool Snake_UpdateBodyPosition(IntPtr snakePtr);

    [DllImport("SnakePlugin")]
    [return: MarshalAs(UnmanagedType.I1)]
    static extern bool Snake_CheckForCollision(IntVector2 appleIndex, IntPtr snakePtr);

    [DllImport("SnakePlugin")]
    static extern int Snake_Expand(IntPtr snakePtr);
}
