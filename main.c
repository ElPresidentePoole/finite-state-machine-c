#include <raylib.h>
#include <stdio.h>
#include "fsm_state.h"

int main() {
  State* main_menu_state_ptr = malloc(sizeof(State));
  main_menu_state_ptr->update = &s_mainmenu_update;
  main_menu_state_ptr->render = &s_mainmenu_render;

  StateMachine state_manager;
  state_manager.curr_state = main_menu_state_ptr;

  const int screenWidth = 800;
  const int screenHeight = 450;
  InitWindow(screenWidth, screenHeight, "pet the friend!");
  while (!WindowShouldClose()) {
    state_manager.curr_state->update(&state_manager);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    state_manager.curr_state->render();
    EndDrawing();
  }
  CloseWindow();

  free(main_menu_state_ptr);
  free(state_manager.curr_state);

  return 0;
}
