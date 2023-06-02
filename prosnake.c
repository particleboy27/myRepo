#define _WIN32_WINNT  _WIN32_WINNT_WIN10
#define NTDDI_VERSION NTDDI_WIN10_19H1
#include <SdkDdkVer.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

#define HEIGHT 20U
#define WIDTH 20U

typedef struct GameState {
  unsigned fruitX; // The x coordinate of the fruit, with the origin in the top left corner.
  unsigned fruitY; // And its y coordinate.
  long score;
  bool isGameOver;
  ptrdiff_t snakeLen; // The number of snake segments, including the head.
  unsigned snakeXs[HEIGHT*WIDTH]; // The x-coordinates of each snake segment, from tail to head
                                  // (The x-coordinate of the head is snakeXs[snakeLen-1]).
  unsigned snakeYs[HEIGHT*WIDTH]; // The y-coordinate
} GameState;

int clear_screen(const HANDLE hStdOut) {
    // Write the sequence for clearing the display.
    DWORD written = 0;
    static const wchar_t sequence[] = L"\x1b[2J\x1b[3J";

    if ( !WriteConsoleW( hStdOut, sequence, ARRAYSIZE(sequence), &written, NULL )) {
        return GetLastError();
    } else {
     return 0;
    }
}

void game_init(GameState* const state)
{
    static const unsigned x = WIDTH/2U;
    static const unsigned y = HEIGHT/2U;

    do {
      state->fruitX = rand() % WIDTH;
      state->fruitY = rand() % HEIGHT;
    } while ( state->fruitX == x && state->fruitY == y );

    memset( state, sizeof(*state), 0 );
    state->score = 0;
    state->isGameOver = false;
    state->snakeXs[0] = x;
    state->snakeYs[0] = y;
    state->snakeLen = 1;
}

void draw_screen( const GameState* const state,
                  const HANDLE hStdOut )
{
    char playfield[HEIGHT][WIDTH+1];
    char scoreline[32] = {0};

    clear_screen(hStdOut);

    for ( unsigned i = 0; i < HEIGHT; ++i ) {
      for ( unsigned j = 0; j < WIDTH; ++j ) {
        playfield[i][j] = '.';
      }
      playfield[i][WIDTH] = '\n';
    }

    const ptrdiff_t headPos = state->snakeLen - 1;
    assert( headPos >= 0 );

    for ( ptrdiff_t i = 0; i < headPos; ++i ) {
      assert(state->snakeXs[i] < WIDTH);
      assert(state->snakeYs[i] < HEIGHT);
      playfield[state->snakeYs[i]][state->snakeXs[i]] = '#';
    }

    playfield[state->snakeYs[headPos]][state->snakeXs[headPos]] = '@';
    playfield[state->fruitY][state->fruitX] = '*';

    WriteConsole( hStdOut, playfield, sizeof(playfield), NULL, NULL );
    const DWORD scorelen = snprintf( scoreline,
                                     sizeof(scoreline),
                                     "Score: %ld\n",
                                     state->score );
    WriteConsole( hStdOut, scoreline, scorelen, NULL, NULL );
}

DWORD get_console_mode( const HANDLE h )
{
  DWORD mode;
  if (!GetConsoleMode( h, &mode )) {
    exit(GetLastError());
  }

  return mode;
}

int main(void)
{
    srand(time(NULL));
    const HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    const DWORD originalMode = get_console_mode(hStdOut);

    const DWORD newMode = originalMode | 
                          ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode( hStdOut, newMode ))
    {
       return GetLastError();
    }

    GameState game_state;
    game_init(&game_state);

    draw_screen( &game_state, hStdOut );

    // Restore the mode on the way out to be nice to other command-line applications.
    SetConsoleMode( hStdOut, originalMode );

    return EXIT_SUCCESS;
}