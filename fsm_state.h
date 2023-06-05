#ifndef FSM_STATE_H_
#define FSM_STATE_H_

#include <stdlib.h>
#include <raylib.h>

typedef struct _State State;
typedef struct _StateMachine StateMachine;

void s_mainmenu_update(StateMachine*);
void s_mainmenu_render();
void s_ingame_update(StateMachine*);
void s_ingame_render();

typedef struct _State {
  void (*update)(StateMachine* sm);
  void (*render)();
} State;

typedef struct _StateMachine {
  State* curr_state;
} StateMachine;


#endif // FSM_STATE_H_
