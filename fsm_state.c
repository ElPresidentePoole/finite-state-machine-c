#include "fsm_state.h"

void s_mainmenu_update(StateMachine* sm) {
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    sm->curr_state = malloc(sizeof(State));
    sm->curr_state->update = &s_ingame_update;
    sm->curr_state->render = &s_ingame_render;
  }
}

void s_mainmenu_render() {
  DrawText("Main Menu", 0, 0, 20, BLACK);
}

void s_ingame_update(StateMachine* sm) {

}

void s_ingame_render() {
  DrawText("In Game", 0, 0, 20, BLACK);
}
