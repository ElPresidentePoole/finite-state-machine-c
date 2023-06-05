#include <raylib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fsm_state.h"

int main() {
  StateMachine* state_machine = s_statemachine_create();

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "finite state machine");
  while (state_machine->game_running){
    if(WindowShouldClose()) {
      state_machine->game_running = false;
      break;
    }
    state_machine->curr_state->update(state_machine);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    state_machine->curr_state->render();
    EndDrawing();
  }
  CloseWindow();

  s_statemachine_free(state_machine);

  return 0;
}
