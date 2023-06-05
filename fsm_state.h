#ifndef FSM_STATE_H_
#define FSM_STATE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <raylib.h>

typedef struct _State State;
typedef struct _StateMachine StateMachine;

void s_mainmenu_update(StateMachine*);
void s_mainmenu_render();
void s_ingame_update(StateMachine*);
void s_ingame_render();

StateMachine* s_statemachine_create();
void s_statemachine_free(StateMachine*);

typedef struct _State {
  void (*update)(StateMachine* sm);
  void (*render)();
} State;

typedef struct _StateMachine {
  State main_menu;
  State in_game;
  State quit_confirm;

  State* curr_state;
  bool game_running;
} StateMachine;


#endif // FSM_STATE_H_
