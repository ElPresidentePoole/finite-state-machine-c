#include "fsm_state.h"

void s_mainmenu_update(StateMachine* sm) {
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    sm->curr_state = &sm->in_game;
  }
}

void s_mainmenu_render() {
  DrawText("Main Menu", 0, 0, 20, BLACK);
}

void s_ingame_update(StateMachine* sm) {
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    sm->curr_state = &sm->quit_confirm;
  }
}

void s_ingame_render() {
  DrawText("In Game\n\nPress any key to quit.", 0, 0, 20, BLACK);
}

void s_quitconfirm_update(StateMachine* sm) {
  if(IsKeyPressed(KEY_N)) {
    sm->curr_state = &sm->in_game;
  } else if(IsKeyPressed(KEY_Y)) {
    sm->game_running = false;
  }
}

void s_quitconfirm_render() {
  DrawText("Are you sure you wish to quit?", 0, 0, 20, BLACK);
}

StateMachine* s_statemachine_create() {
  StateMachine* sm = malloc(sizeof(StateMachine));
  sm->main_menu = (State){.render = &s_mainmenu_render, .update = &s_mainmenu_update};
  sm->in_game = (State){.render = &s_ingame_render, .update = &s_ingame_update};
  sm->quit_confirm = (State){.render = &s_quitconfirm_render, .update = &s_quitconfirm_update};
  sm->curr_state = &sm->main_menu;
  sm->game_running = true;
  return sm;
}

void s_statemachine_free(StateMachine* sm) {
  free(sm);
}
