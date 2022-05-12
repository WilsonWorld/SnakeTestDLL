using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Snake : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        InitSnake();
    }

    void OnDestroy()
    {
        //Dispose of IDisposible classes here
        m_Snake.Dispose();
    }

    // Increments the snake's speed each time the snake collides with an apple and gains another body piece.
    void Update()
    {
        HandleInput();

        m_AccumulatedTime += Time.deltaTime;
        if(m_AccumulatedTime >= m_UpdateRate) {
            m_AccumulatedTime = 0.0f;
        
            StopUpdate = m_Snake.UpdateBodyPosition();

            if (StopUpdate == true)
                return;
           
            if (m_Snake.CheckForCollision(Grid.Instance.GetAppleIndex())) {
                m_BodyPieceCount = m_Snake.Expand();
                m_UpdateRate *= 0.8f;
                Grid.Instance.SpawnApple();
            }

            Grid.Instance.DrawSnake(m_SnakeBody, m_BodyPieceCount);
        }
    }

    // Check for player input to change movement direction or restart the game
    void HandleInput()
    {
        if (StopUpdate == true)
            return;

        if (Input.GetKeyDown(KeyCode.UpArrow) || Input.GetKeyDown(KeyCode.W)) {
            m_Snake.SetNewDirection(new IntVector2(0, 1));
        }
        if (Input.GetKeyDown(KeyCode.DownArrow) || Input.GetKeyDown(KeyCode.S)) {
            m_Snake.SetNewDirection(new IntVector2(0, -1));
        }
        if (Input.GetKeyDown(KeyCode.RightArrow) || Input.GetKeyDown(KeyCode.D)) {
            m_Snake.SetNewDirection(new IntVector2(1, 0));
        }
        if (Input.GetKeyDown(KeyCode.LeftArrow) || Input.GetKeyDown(KeyCode.A)) {
            m_Snake.SetNewDirection(new IntVector2(-1, 0));
        }

        if (Input.GetKeyDown(KeyCode.Space)) {
            Grid.Instance.RestartGame();
            ResetSnake();
        }

        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
        }
    }

    // Set up the snake object the player controls
    void InitSnake()
    {
        m_UpdateRate = 0.3f;
        m_AccumulatedTime = m_UpdateRate;

        m_BodyPieceCount = 1;
        m_MaxBodyPieceCount = 10;
        m_SnakeBody = new IntVector2[m_MaxBodyPieceCount];

        //Setting initial head position
        m_Snake = new SnakeGlue(new IntVector2(0, 0), m_MaxBodyPieceCount, m_SnakeBody);
    }

    // Destroy the old snake and start with a fresh one, and spawn in a new Apple.
    void ResetSnake()
    {
        OnDestroy();

        InitSnake();
        Grid.Instance.SpawnApple();
    }

    bool StopUpdate = false;
    float m_AccumulatedTime;
    float m_UpdateRate;
    int m_BodyPieceCount;
    int m_MaxBodyPieceCount;
    IntVector2 m_MovementDirection;
    IntVector2[] m_SnakeBody;
    SnakeGlue m_Snake;
}
