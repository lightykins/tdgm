#ifndef GAMESTATE_INCLUDED
#define GAMESTATE_INCLUDED

class CGameState
{
public:
  void Init();
  void Cleanup();

  void ChangeState(CGameState* state);
  void PushState(CGameState* state);
  void PopState();

  void HandleEvents();
  void Update();
  void Draw();

  bool Running() { return m_running; }
  void Quit() { m_running = false; }

private:
  // the stack of states
  vector<CGameState*> states;

  bool m_running;
};

#endif